<?php
/**
 * @file
 * Provides API documentation for Blue OI External Payment.
 */

/**
 * Implements hook_blueoi_commerce_external_payment_payment_type_options_alter().
 */
function hook_blueoi_commerce_external_payment_payment_type_options_alter(&$options) {
  // Add plasma as a payment type.
  $options[] = t('Plasma');
}
