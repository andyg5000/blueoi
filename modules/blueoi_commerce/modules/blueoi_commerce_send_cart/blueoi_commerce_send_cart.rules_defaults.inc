<?php

/**
 * @file
 * Default rules for BlueOI Commerce Send Cart.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function blueoi_commerce_send_cart_default_rules_configuration() {
  $configs = array();
  $configs['blueoi_commerce_send_cart_send_cart_email'] = entity_import('rules_config', '{ "blueoi_commerce_send_cart_send_cart_email" : {
      "LABEL" : "Send a cart via email",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "blueoi_commerce_send_cart" ],
      "ON" : { "blueoi_commerce_send_cart_send" : [] },
      "IF" : [
        { "NOT data_is_empty" : { "data" : [ "to" ] } },
        { "NOT data_is_empty" : { "data" : [ "message" ] } }
      ],
      "DO" : [
        { "drupal_message" : {
            "message" : "The order has been emailed to [to:value]. The URL [site:url]cart\/receive\/[order:order-id] can be used to receive the order.\r\n",
            "repeat" : "0"
          }
        },
        { "mail" : {
            "to" : [ "to" ],
            "subject" : [ "subject" ],
            "message" : "[message:value]\r\n\r\nClick the link below to view your order:\r\n[site:url]cart\/receive\/[order:order-id]\r\n",
            "from" : [ "site:mail" ],
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $configs;
}
