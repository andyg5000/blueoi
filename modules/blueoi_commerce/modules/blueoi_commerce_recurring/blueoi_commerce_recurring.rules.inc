<?php

/**
 * @file
 * Provides rules integration.
 */
/**
 * Implements hook_rules_event_info().
 */
function blueoi_commerce_recurring_rules_event_info() {
  $info = array();
  $info['blueoi_commerce_recurring_cl_billing_cycle_canceled'] = array(
    'label' => t('Billing cycle canceled'),
    'group' => t('Commerce License Billing Cycle'),
    'variables' => array(
      'cl_billing_cycle' => array(
        'type' => 'cl_billing_cycle',
        'label' => t('Billing Cycle'),
      ),
    ),
  );
  return $info;
}
