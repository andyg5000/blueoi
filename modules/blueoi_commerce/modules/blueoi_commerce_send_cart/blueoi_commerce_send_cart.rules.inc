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
