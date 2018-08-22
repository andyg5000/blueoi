<?php
/**
 * @file
 * Provides default rules.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function blueoi_commerce_abandoned_cart_default_rules_configuration() {
  $config = array();

  // Rules component to create and send abandoned cart notifications.
  $config['blueoi_create_and_send_abandoned_cart_notice'] = entity_import('rules_config', '{ "blueoi_create_and_send_abandoned_cart_notice" : {
      "LABEL" : "Create and send abandoned cart notification",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [
        "commerce_cart",
        "commerce_order",
        "rules",
        "blueoi_commerce_send_cart",
        "message_notify",
        "rules_scheduler"
      ],
      "USES VARIABLES" : { "commerce_order" : { "label" : "Commerce Order", "type" : "commerce_order" } },
      "IF" : [
        { "commerce_order_is_cart" : { "commerce_order" : [ "commerce_order" ] } },
        { "commerce_order_compare_total_product_quantity" : {
            "commerce_order" : [ "commerce_order" ],
            "operator" : "\u003E=",
            "value" : "1"
          }
        },
        { "NOT data_is_empty" : { "data" : [ "commerce-order:mail" ] } }
      ],
      "DO" : [
        { "blueoi_commerce_send_cart_rules_mark_order_sent" : { "commerce_order" : [ "commerce_order" ] } },
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "blueoi_commerce_abandoned_cart",
              "param_user" : "1"
            },
            "PROVIDE" : { "entity_created" : { "message" : "Message" } }
          }
        },
        { "data_set" : {
            "data" : [ "message:blueoi-message-order-ref" ],
            "value" : [ "commerce-order" ]
          }
        },
        { "entity_save" : { "data" : [ "message" ], "immediate" : "1" } },
        { "message_notify_process" : { "message" : [ "message" ], "mail" : "[commerce-order:mail]" } },
        { "schedule_delete" : {
            "component" : "blueoi_create_and_send_abandoned_cart_notice",
            "task" : "abandoned-cart-[commerce-order:order-id]"
          }
        }
      ]
    }
  }');

  // Rule to schedule abandoned cart notifications for
  $config['blueoi_commerce_abandoned_cart_schedule'] = entity_import('rules_config', '{ "blueoi_commerce_abandoned_cart_schedule" : {
      "LABEL" : "Schedule abandoned cart notification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_cart", "rules", "rules_scheduler", "entity" ],
      "ON" : { "commerce_order_update" : [] },
      "IF" : [
        { "commerce_order_is_cart" : { "commerce_order" : [ "commerce_order" ] } }
      ],
      "DO" : [
        { "schedule" : {
            "component" : "blueoi_create_and_send_abandoned_cart_notice",
            "date" : "+1 hour",
            "identifier" : "abandoned-cart-[commerce-order:order-id]",
            "param_commerce_order" : [ "commerce-order" ]
          }
        }
      ]
    }
  }');

  $config['blueoi_commerce_abandoned_cart_cancel'] = entity_import('rules_config', '{ "blueoi_commerce_abandoned_cart_cancel" : {
      "LABEL" : "Cancel abandoned cart notifications",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_cart", "rules", "rules_scheduler", "entity" ],
      "ON" : { "commerce_order_update" : [] },
      "IF" : [
        { "NOT commerce_order_is_cart" : { "commerce_order" : [ "commerce_order" ] } }
      ],
      "DO" : [
        { "schedule_delete" : {
            "component" : "blueoi_create_and_send_abandoned_cart_notice",
            "task" : "abandoned-cart-[commerce-order:order-id]"
          }
        }
      ]
    }
  }');

  return $config;
}