<?php

/**
 * @file
 * Provides rules integration.
 */

/**
 * Implements hook_rules_condition_info().
 */
function blueoi_commerce_rules_rules_condition_info() {
  $info = array();
  $info['blueoi_commerce_rules_owner_has_purchased_skus'] = array(
    'label' => t('User has purchased SKUs'),
    'group' => t('BlueOI'),
    'parameter' => array(
      'user' => array(
        'type' => 'user',
        'label' => t('User'),
      ),
      'skus' => array(
        'type' => 'text',
        'label' => 'SKUs',
        'description' => t('Enter SKUs 1 per line'),
      ),
      'include_cart' => array(
        'type' => 'boolean',
        'label' => t('Include active cart'),
      ),
      'exclude_id' => array(
        'type' => 'integer',
        'label' => t('Exclude order id'),
        'optional' => TRUE,
      ),
    ),
    'callbacks' => array(
      'execute' => 'blueoi_commerce_rules_owner_has_purchased_skus',
    ),
  );
  return $info;
}
