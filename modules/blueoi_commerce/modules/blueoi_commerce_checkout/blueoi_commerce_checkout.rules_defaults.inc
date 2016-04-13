<?php

/**
 * @file
 * Provides default rules for BlueOI Commerce Checkout.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function blueoi_commerce_checkout_default_rules_configuration() {
  $rules = array();

  $rules['blueoi_commerce_checkout_create_new_user_from_order'] = entity_import('rules_config', '{ "blueoi_commerce_checkout_create_new_user_from_order" : {
      "LABEL" : "Create a new user account from an anonymous order",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce" ],
      "USES VARIABLES" : { "commerce_order" : { "label" : "Commerce Order", "type" : "commerce_order" } },
      "IF" : [
        { "data_is" : { "data" : [ "commerce-order:owner" ], "value" : "0" } },
        { "NOT entity_exists" : {
            "type" : "user",
            "property" : "mail",
            "value" : [ "commerce-order:mail" ]
          }
        },
        { "data_is" : { "data" : [ "commerce-order:type" ], "value" : "commerce_order" } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "user",
              "param_name" : [ "commerce-order:mail-username" ],
              "param_mail" : [ "commerce-order:mail" ]
            },
            "PROVIDE" : { "entity_created" : { "account_created" : "Account created" } }
          }
        },
        { "data_set" : { "data" : [ "account-created:status" ], "value" : "1" } },
        { "entity_save" : { "data" : [ "account-created" ], "immediate" : 1 } },
        { "data_set" : { "data" : [ "commerce-order:uid" ], "value" : [ "account-created:uid" ] } },
        { "entity_save" : { "data" : [ "commerce-order" ], "immediate" : 1 } }
      ]
    }
  }');

  return $rules;
}
