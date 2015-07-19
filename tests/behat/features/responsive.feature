Feature: Responsive product facet search api
  In order to have a better view of product search on mobile
  As any user
  I should see concise search facets

  @javascript @demo
  Scenario: Search facets should be presented as select lists
    When I go to "/products"
    When I click "To wear (12)"
    Then I should see "There are 12 search results"
    When I click "(-) "
    When I resize the browser to mobile
    When I select "Select a collection..." from "selectnav3"
    When I select "To wear (12)" from "selectnav3"
