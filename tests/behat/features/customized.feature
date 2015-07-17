@no-demo @api
Feature: Customizations to non-demo store stay
  In order to customize my site
  As a site builder
  I need Commerce Kickstart to respect my changes

  Background:
    Given I am logged in as a user with the "administrator" role

  Scenario: My changes to Product Display teaser view mode stay
    When I am on "/admin/structure/types/manage/product-display/display/teaser"

    # Verify custom visible.
    Then the "edit-fields-productsku-type" field should contain "visible"
    Then the "edit-fields-producttitle-field-type" field should contain "visible"
    Then the "edit-fields-productcommerce-price-type" field should contain "visible"

    # Verify hidden.
    Then the "edit-fields-body-type" field should contain "hidden"
    Then the "edit-fields-title-field-type" field should contain "hidden"
    Then the "edit-fields-productfield-images-type" field should contain "hidden"

  Scenario: Changes to the Product Display type stay
    When I am on "/admin/structure/types/manage/product-display"
    Then the "edit-name" field should contain "Product display (altered)"
    Then the "edit-description" field should contain "This is the description of the product display"
    Then the "edit-node-options-status" field should contain ""
    Then the "edit-comment--2" field should contain "0"

  Scenario: Changes to the Product Display body field instance
    When I am on "/admin/structure/types/manage/product-display/fields/body"
    Then the "edit-instance-label" field should contain "Description"
    Then the "edit-instance-required" field should contain "1"
    Then the "edit-instance-description" field should contain "Description of the product"
    Then the "edit-instance-widget-settings-rows" field should contain "10"

  Scenario: Product category kept field widget change
    When I am on "/admin/structure/types/manage/product-display/fields/field_product_category/widget-type"
    Then the "edit-widget-type" field should contain "taxonomy_autocomplete"

  Scenario: Product variation field display settings did not change
    When I am on "/admin/commerce/config/product-variation-types/product/display"
    Then I should see "Image style: Large (480x480)"
