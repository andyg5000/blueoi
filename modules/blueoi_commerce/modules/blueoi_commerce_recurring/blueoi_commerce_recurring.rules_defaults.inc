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
  if (!empty($configs['rules_commerce_license_billing_charge_recurring_order'])) {
    $configs['rules_commerce_license_billing_charge_recurring_order']->condition('component_blueoi_comerce_recurring_site_is_production');
  }
}
