<?php

/**
 * @file
 * Rules integration for BlueOI Commerce Send Cart.
 */

/**
 * Implements hook_rules_event_info().
 */
function blueoi_commerce_send_cart_rules_event_info() {
  $events = array();
  $events['blueoi_commerce_send_cart_send'] = array(
    'label' => t('Send a cart via email'),
    'group' => t('BlueOI'),
    'variables' => array(
      'to' => array(
        'type' => 'text',
        'label' => t('To'),
      ),
      'subject' => array(
        'type' => 'text',
        'label' => t('Subject'),
      ),
      'message' => array(
        'type' => 'text',
        'label' => t('Message'),
      ),
      'order' => array(
        'type' => 'commerce_order',
      ),
    ),
  );
  return $events;
}

/**
 * Implements hook_rules_action_info().
 */
function blueoi_commerce_send_cart_rules_action_info() {
  $actions = array();
  $actions['blueoi_commerce_send_cart_rules_mark_order_sent'] = array(
    'label' => t('Allow order to be sent'),
    'description' => t('Allows an order to reassigned via link'),
    'group' => 'BlueOI',
    'parameter' => array(
      'commerce_order' => array(
        'type' => 'commerce_order',
        'label' => t('Commerce Order'),
      )
    ),
    'callbacks' => array(
      'execute' => 'blueoi_commerce_send_cart_rules_mark_order_sent',
    ),
  );
  return $actions;
}

/**
 * Rules action callback to mark the order as sent.
 * @param $order
 */
function blueoi_commerce_send_cart_rules_mark_order_sent($order) {
  // Set the sent flag on this order, so it can be adopted
  // to another user or anonymous via link.
  $order->data['blueoi_commerce_send_cart']['sent'] = TRUE;
  commerce_order_save($order);
}
