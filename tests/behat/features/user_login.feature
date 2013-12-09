@user @login
Feature: Login Commerce Kickstart
  In order to start using additional features of the site
  As an anonymous user
  I should be able to Login

  Scenario: View the Login page
    When I go to "/user/login"
    Then I should see "Login"
      And I should see the following <links>
        | links                    |
        | Forgot your password?    |
        | Create an account        |

  @validation
  Scenario Outline: Username validation: Valid username
    When I go to "/user/login"
      And I fill in "Username" with "<name>"
      And I fill in "Password" with random text
      And I press "Log in"
    Then I should see "Sorry, unrecognized username or password."
      And the field "Username" should be outlined in red
  Examples:
    | name           |
    | randomname     |
    | 123453         |
    | mail@mail.com  |

  @api
  Scenario: Login and as admin and view user profile
    When I am logged in as a user with the "administrator" role
      And I go to "/user"
    Then I should see the following <links>
      | links                 |
      | My account            |
      | Address Book          |
      | Update email/password |
      | Connections           |
      | Order history         |

