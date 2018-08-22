<?php

/**
 * @file
 * Provides rules integration for BlueOI Commerce Order Message.
 */

/**
 * Implements hook_rules_event_info().
 */
function blueoi_commerce_order_message_rules_event_info() {
  $events = array();
  $events['blueoi_commerce_order_message_notify_customer'] = array(
    'label' => t('Notify customer on order update'),
    'group' => t('Commerce Order'),
    'variables' => array(
      'commerce_order' => array(
        'type' => 'commerce_order',
        'label' => t('Commerce Order'),
      ),
      'log' => array(
        'type' => 'text',
        'label' => t('Log message'),
      )
    ),
  );
  return $events;
}
