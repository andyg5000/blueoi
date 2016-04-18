<?php
/**
 * @file
 * Defines Drupal API methods exposed by this module.
 */

/**
 * Implements hook_blueoi_mail_themed_mail_view().
 *
 * Exposes a hook that allows you to return a render array
 * which will be used to as the body content in the template
 * rendered at /blueoi/themed-email.
 *
 * If testing message entity templates, you can use the helper
 * method blueoi_mail_simulate_message() to simulate token
 * replacement.
 *
 * @return array
 *   Return any render array to be placed in the mail template.
 */
function hook_blueoi_mail_themed_mail_view() {
  // Create a message via rules (ie: an order confirmation).
  // Load that message
  $message_id = 13000;
  $message = entity_load_single('message', $message_id);

  // Build the markup that you'll eventually place in your message
  // template.
  $markup = '
    <strong>Order Details</strong>
      [message:field-message-order:commerce_extra_tokens_line_items]
      [message:field-message-order:commerce_extra_tokens_total]
    </p>
  ';

  // Return the markup processed by the included simulate
  // message routine which does token replacement on the
  // markup.
  return array(
    '#markup' => blueoi_mail_simulate_message($markup, $message),
  );
}
