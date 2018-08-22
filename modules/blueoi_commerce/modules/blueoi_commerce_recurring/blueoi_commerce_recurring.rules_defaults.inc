<?php

/**
 * @file
 * Provides default rules for BlueOI Commerce Recurring.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function blueoi_commerce_recurring_default_rules_configuration() {
  $configs = array();
  $configs['blueoi_comerce_recurring_site_is_production'] = entity_import('rules_config', '{ "rules_site_is_running_on_production_server" : {
      "LABEL" : "Site is running on production server",
      "PLUGIN" : "and",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules_server_variables" ],
      "AND" : [
        { "rules_server_variables_compare" : {
            "variable" : "' . variable_get('blueoi_commerce_recurring_production_check_key', 'HTTP_HOST'). '",
            "value" : "' . variable_get('blueoi_commerce_recurring_production_check_value', 'example.com') . '",
            "operator" : "equal_to"
          }
        }
      ]
    }
  }');
  return $configs;
}

/**
 * Implements hook_default_rules_configuration_alter().
 */
function blueoi_commerce_recurring_default_rules_configuration_alter(&$configs) {
  // Define all rules that should only fire on production
  $production_rules = array(
    'rules_commerce_dunning_schedule_charge_attempts',
    'rules_commerce_dunning_charge_card',
    'commerce_license_billing_set_postpaid_product_price',
    'commerce_license_billing_prorate_prepaid_product_price',
    'commerce_license_billing_prorate_recurring_line_item',
    'commerce_license_billing_create_recurring_orders',
    'rules_commerce_license_billing_charge_recurring_order',
    'rules_commerce_license_billing_update_order_charged',
  );

  // Loop over all production rules and require the production component condition.
  foreach ($production_rules as $production_rule) {
    if (!empty($configs[$production_rule])) {
      $configs[$production_rule]->condition('component_blueoi_comerce_recurring_site_is_production');
    }
  }
}
