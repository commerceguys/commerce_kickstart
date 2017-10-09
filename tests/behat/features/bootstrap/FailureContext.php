<?php

use Behat\Mink\Driver\Selenium2Driver;
use Behat\Behat\Hook\Scope\AfterStepScope;
use Behat\Behat\Context\Context;
use Behat\Behat\Hook\Scope\BeforeScenarioScope;

class FailureContext implements Context {

  /**
   * @var \Drupal\DrupalExtension\Context\MinkContext
   */
  protected $minkContext;
  protected $failurePath;

  /**
   * @BeforeScenario
   */
  public function prepare(BeforeScenarioScope $scope) {
    $this->minkContext = $scope->getEnvironment()->getContext('Drupal\DrupalExtension\Context\MinkContext');
    $this->failurePath = $scope->getEnvironment()->getSuite()->getSetting('failure_path');
  }

  /**
   * @AfterStep
   */
  public function handleFailure(AfterStepScope $scope) {

    if (99 !== $scope->getTestResult()->getResultCode()) {
      return;
    }

    $fileName = $this->fileName($scope);
    $this->dumpMarkup($fileName);
    $this->screenShot($fileName);
  }

  /**
   * @Then /^I take an awesome screenshot$/
   */
  public function takeScreenShot() {
    $fileName = $this->fileName();
    $this->dumpMarkup($fileName);
    $this->screenShot($fileName);
  }

  /**
   * Compute a file name for the output.
   */
  protected function fileName($scope = NULL) {
    if ($scope) {
      $baseName = pathinfo($scope->getFeature()->getFile());
      $baseName = substr($baseName['basename'], 0 , strlen($baseName['basename']) - strlen($baseName['extension']) - 1);
      $baseName .= '-' . $scope->getStep()->getLine();
    }
    else {
      $baseName = 'screenshot';
    }

    $baseName .= '-' . date('YmdHis');
    $baseName = $this->failurePath . '/' . $baseName;
    return $baseName;
  }

  /**
   * Save the markup from the failed step.
   */
  protected function dumpMarkup($fileName) {
    $fileName .= '.html';
    $html = $this->minkContext->getSession()->getPage()->getHtml();
    file_put_contents($fileName, $html);
    sprintf("HTML available at: %s\n", $fileName);
  }

  /**
   * Save a screen shot from the failed step.
   */
  protected function screenShot($fileName) {
    $fileName .= '.png';
    $driver = $this->minkContext->getSession()->getDriver();

    if ($driver instanceof Selenium2Driver) {
      file_put_contents($fileName, $this->minkContext->getSession()->getDriver()->getScreenshot());
      sprintf("Screen shot available at: %s\n", $fileName);
      return;
    }
  }
}
