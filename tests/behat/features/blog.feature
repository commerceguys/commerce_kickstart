Feature: Blog
  In order to read more about the store
  As any user
  I should be able to see the blog

  Background:
    Given I am on the homepage
    When I click "Blog"
    Then I should see the heading "Blog"

  Scenario: Categories should pull relevant blog posts
    When I click "Kickstart Tip"
    Then I should see the heading "Blog - Category: Kickstart Tip"
    And I should see "Social logins made simple"

  Scenario: Comments should be closed for anonymous users
    When I click "Social Logins Made Simple"
    Then I should see the heading "Social Logins Made Simple"
    Then I should see "Log in or register to post comments"

  @drush
  Scenario: Comments should be closed for authenticated users
    When I am logged in as a user with the "authenticated user" role
    When I click "Blog"
    When I click "Social Logins Made Simple"
    Then I should see the heading "Social Logins Made Simple"
    Then I should not see "Log in or register to post comments"