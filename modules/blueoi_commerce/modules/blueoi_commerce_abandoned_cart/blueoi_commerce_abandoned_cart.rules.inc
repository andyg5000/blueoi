<?php
/**
 * @file
 * Provides rules integration.
 */

/**
 * Implements hook_rules_condition_info().
 */
function blueoi_commerce_abandoned_cart_rules_condition_info() {
  $conditions = array();
  $conditions['blueoi_commerce_abandoned_cart_count_less_than'] = array(
    'label' => t('Abandoned cart count less than'),
    'group' => 'BlueOI',
    'parameter' => array(
      'commerce_order' => array(
        'type' => 'commerce_order',
        'label' => t('Commerce Order'),
      ),
      'count' => array(
        'type' => 'integer',
        'label' => t('Count'),
      ),
    ),
    'callbacks' => array(
      'execute' => 'blueoi_commerce_abandoned_cart_count_less_than',
    )
  );
  return $conditions;
}

/**
 * Implements hook_rules_action_info().
 */
function blueoi_commerce_abandoned_cart_rules_action_info() {
  $actions = array();
  $actions['blueoi_commerce_abandoned_cart_increment_count'] = array(
    'label' => t('Increment abandoned cart notification count'),
    'group' => 'BlueOI',
    'parameter' => array(
      'commerce_order' => array(
        'type' => 'commerce_order',
        'label' => t('Commerce Order'),
      )
    ),
    'callbacks' => array(
      'execute' => 'blueoi_commerce_abandoned_cart_increment_count',
    )
  );
  return $actions;
}

/**
 * Rules condition for abandoned cart count.
 */
function blueoi_commerce_abandoned_cart_count_less_than($order, $count) {
  if (!empty($order->data['blueoi_commerce_abandoned_cart']['count'])) {
    return $order->data['blueoi_commerce_abandoned_cart']['count'] < $count;
  }
  return TRUE;
}

/**
 * Rules action callback to increment notification count.
 */
function blueoi_commerce_abandoned_cart_increment_count($order) {
  if (!empty($order->data['blueoi_commerce_abandoned_cart']['count'])) {
    $order->data['blueoi_commerce_abandoned_cart']['count']++;
  }
  else {
    $order->data['blueoi_commerce_abandoned_cart']['count'] = 1;
  }
  commerce_order_save($order);
}
