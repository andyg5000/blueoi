<?php

/**
 * @file
 * Provides default rules for BlueOI Commerce Order Message.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function blueoi_commerce_order_message_default_rules_configuration() {
  $rules = array();
  $rules['blueoi_commerce_order_message_send'] = entity_import('rules_config', '{ "blueoi_commerce_order_message_send" : {
      "LABEL" : "Send customer order update notification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "message_notify", "blueoi_commerce_order_message" ],
      "ON" : { "blueoi_commerce_order_message_notify_customer" : [] },
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "blueoi_commerce_order_message",
              "param_user" : [ "commerce-order:owner" ]
            },
            "PROVIDE" : { "entity_created" : { "message" : "Message" } }
          }
        },
        { "data_set" : {
            "data" : [ "message:blueoi-message-order-ref" ],
            "value" : [ "commerce-order" ]
          }
        },
        { "data_set" : { "data" : [ "message:blueoi-message-log" ], "value" : [ "log" ] } },
        { "entity_save" : { "data" : [ "message" ], "immediate" : "1" } },
        { "message_notify_process" : { "message" : [ "message" ], "mail" : "[commerce-order:mail]" } },
        { "drupal_message" : {
            "message" : "Update message for order [commerce-order:order-number] sent to [commerce-order:mail].",
            "repeat" : "0"
          }
        }
      ]
    }
  }');
  return $rules;
}
