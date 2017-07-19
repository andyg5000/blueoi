<?php

/**
 * @file
 * Provides views integration.
 */

/**
 * Implements hook_views_default_views().
 */
function blueoi_commerce_recurring_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'blueoi_commerce_recurring_orders';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_order';
  $view->human_name = 'Recurring Orders';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Recurring Order Management';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer commerce_order entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '150';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'order_id' => 'order_id',
    'name' => 'name',
    'first_name' => 'first_name',
    'last_name' => 'last_name',
    'line_item_title' => 'line_item_title',
    'commerce_order_total' => 'commerce_order_total',
    'owner' => 'owner',
    'license_id' => 'license_id',
    'expires' => 'expires',
    'name_1' => 'name_1',
    'status' => 'status',
    'status_1' => 'status_1',
    'status_2' => 'status_2',
    'status_3' => 'status_3',
  );
  $handler->display->display_options['style_options']['default'] = 'expires';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'order_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'line_item_title' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_order_total' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'owner' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'license_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'expires' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status_2' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status_3' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results match your search.';
  $handler->display->display_options['empty']['area']['format'] = 'wysiwyg_editor';
  /* Relationship: Commerce Order: Owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'Drupal User';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: Commerce Order: Referenced line items */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['label'] = 'Line items';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['cl_billing_license_target_id']['id'] = 'cl_billing_license_target_id';
  $handler->display->display_options['relationships']['cl_billing_license_target_id']['table'] = 'field_data_cl_billing_license';
  $handler->display->display_options['relationships']['cl_billing_license_target_id']['field'] = 'cl_billing_license_target_id';
  $handler->display->display_options['relationships']['cl_billing_license_target_id']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['cl_billing_license_target_id']['label'] = 'License';
  $handler->display->display_options['relationships']['cl_billing_license_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['cl_billing_cycle_target_id']['id'] = 'cl_billing_cycle_target_id';
  $handler->display->display_options['relationships']['cl_billing_cycle_target_id']['table'] = 'field_data_cl_billing_cycle';
  $handler->display->display_options['relationships']['cl_billing_cycle_target_id']['field'] = 'cl_billing_cycle_target_id';
  $handler->display->display_options['relationships']['cl_billing_cycle_target_id']['label'] = 'Billing Cycle';
  $handler->display->display_options['relationships']['cl_billing_cycle_target_id']['required'] = TRUE;
  /* Relationship: Commerce License: Owner uid */
  $handler->display->display_options['relationships']['owner']['id'] = 'owner';
  $handler->display->display_options['relationships']['owner']['table'] = 'commerce_license';
  $handler->display->display_options['relationships']['owner']['field'] = 'owner';
  $handler->display->display_options['relationships']['owner']['relationship'] = 'cl_billing_license_target_id';
  $handler->display->display_options['relationships']['owner']['label'] = 'License Assigned';
  /* Relationship: User: Commerce Card on File */
  $handler->display->display_options['relationships']['commerce_cardonfile']['id'] = 'commerce_cardonfile';
  $handler->display->display_options['relationships']['commerce_cardonfile']['table'] = 'users';
  $handler->display->display_options['relationships']['commerce_cardonfile']['field'] = 'commerce_cardonfile';
  $handler->display->display_options['relationships']['commerce_cardonfile']['relationship'] = 'uid';
  /* Field: Bulk operations: Commerce Order */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::segd_recurring_rules_cancel_recurring_order' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Commerce License Billing Cycle: Billing cycle ID */
  $handler->display->display_options['fields']['billing_cycle_id']['id'] = 'billing_cycle_id';
  $handler->display->display_options['fields']['billing_cycle_id']['table'] = 'cl_billing_cycle';
  $handler->display->display_options['fields']['billing_cycle_id']['field'] = 'billing_cycle_id';
  $handler->display->display_options['fields']['billing_cycle_id']['relationship'] = 'cl_billing_cycle_target_id';
  $handler->display->display_options['fields']['billing_cycle_id']['label'] = 'Billing ID';
  $handler->display->display_options['fields']['billing_cycle_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['billing_cycle_id']['separator'] = '';
  /* Field: Commerce License: License ID */
  $handler->display->display_options['fields']['license_id']['id'] = 'license_id';
  $handler->display->display_options['fields']['license_id']['table'] = 'commerce_license';
  $handler->display->display_options['fields']['license_id']['field'] = 'license_id';
  $handler->display->display_options['fields']['license_id']['relationship'] = 'cl_billing_license_target_id';
  $handler->display->display_options['fields']['license_id']['label'] = '';
  $handler->display->display_options['fields']['license_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['license_id']['alter']['path'] = 'user/[owner]/my-memberships/[license_id]?destination=admin/commerce/orders/recurring';
  $handler->display->display_options['fields']['license_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['license_id']['separator'] = '';
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['link_to_order'] = 'admin';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Purchased By User';
  /* Field: Commerce Line Item: Title */
  $handler->display->display_options['fields']['line_item_title']['id'] = 'line_item_title';
  $handler->display->display_options['fields']['line_item_title']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['line_item_title']['field'] = 'line_item_title';
  $handler->display->display_options['fields']['line_item_title']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['line_item_title']['label'] = 'Item';
  /* Field: Commerce Order: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce License: Owner uid */
  $handler->display->display_options['fields']['owner']['id'] = 'owner';
  $handler->display->display_options['fields']['owner']['table'] = 'commerce_license';
  $handler->display->display_options['fields']['owner']['field'] = 'owner';
  $handler->display->display_options['fields']['owner']['relationship'] = 'cl_billing_license_target_id';
  $handler->display->display_options['fields']['owner']['label'] = '';
  $handler->display->display_options['fields']['owner']['exclude'] = TRUE;
  $handler->display->display_options['fields']['owner']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['owner']['separator'] = '';
  /* Field: Commerce License Billing Cycle: End */
  $handler->display->display_options['fields']['end']['id'] = 'end';
  $handler->display->display_options['fields']['end']['table'] = 'cl_billing_cycle';
  $handler->display->display_options['fields']['end']['field'] = 'end';
  $handler->display->display_options['fields']['end']['relationship'] = 'cl_billing_cycle_target_id';
  $handler->display->display_options['fields']['end']['label'] = 'Ends';
  $handler->display->display_options['fields']['end']['date_format'] = 'short';
  $handler->display->display_options['fields']['end']['second_date_format'] = 'long';
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Order Status';
  /* Field: Commerce License: Status */
  $handler->display->display_options['fields']['status_1']['id'] = 'status_1';
  $handler->display->display_options['fields']['status_1']['table'] = 'commerce_license';
  $handler->display->display_options['fields']['status_1']['field'] = 'status';
  $handler->display->display_options['fields']['status_1']['relationship'] = 'cl_billing_license_target_id';
  $handler->display->display_options['fields']['status_1']['label'] = 'License Status';
  /* Field: Commerce License Billing Cycle: Status */
  $handler->display->display_options['fields']['status_2']['id'] = 'status_2';
  $handler->display->display_options['fields']['status_2']['table'] = 'cl_billing_cycle';
  $handler->display->display_options['fields']['status_2']['field'] = 'status';
  $handler->display->display_options['fields']['status_2']['relationship'] = 'cl_billing_cycle_target_id';
  $handler->display->display_options['fields']['status_2']['label'] = 'Recurring Status';
  $handler->display->display_options['fields']['status_2']['not'] = 0;
  /* Field: Commerce Card on File: Card Status */
  $handler->display->display_options['fields']['status_3']['id'] = 'status_3';
  $handler->display->display_options['fields']['status_3']['table'] = 'commerce_cardonfile';
  $handler->display->display_options['fields']['status_3']['field'] = 'status';
  $handler->display->display_options['fields']['status_3']['relationship'] = 'commerce_cardonfile';
  $handler->display->display_options['fields']['status_3']['empty'] = '<strong style="color:red">Bad Card</strong>';
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = array(
    'dunning_past_due' => 'dunning_past_due',
    'canceled' => 'canceled',
    'pending' => 'pending',
    'processing' => 'processing',
    'recurring_open' => 'recurring_open',
    'completed' => 'completed',
  );
  $handler->display->display_options['filters']['status_1']['group'] = 1;
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    'canceled' => 'canceled',
    'dunning_past_due' => 'dunning_past_due',
    'pending' => 'pending',
    'processing' => 'processing',
    'completed' => 'completed',
    'recurring_open' => 'recurring_open',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['status']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['status']['group_info']['label'] = 'Order status';
  $handler->display->display_options['filters']['status']['group_info']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['status']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Drupal User';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    11 => 0,
    7 => 0,
    13 => 0,
    5 => 0,
    4 => 0,
    12 => 0,
    8 => 0,
    6 => 0,
    10 => 0,
    9 => 0,
  );
  /* Filter criterion: Date: Date (commerce_license) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'commerce_license';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['relationship'] = 'cl_billing_license_target_id';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'not empty';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Expiration';
  $handler->display->display_options['filters']['date_filter']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'commerce_license.expires' => 'commerce_license.expires',
  );
  /* Filter criterion: Commerce License: Status */
  $handler->display->display_options['filters']['status_2']['id'] = 'status_2';
  $handler->display->display_options['filters']['status_2']['table'] = 'commerce_license';
  $handler->display->display_options['filters']['status_2']['field'] = 'status';
  $handler->display->display_options['filters']['status_2']['relationship'] = 'cl_billing_license_target_id';
  $handler->display->display_options['filters']['status_2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status_2']['expose']['operator_id'] = 'status_2_op';
  $handler->display->display_options['filters']['status_2']['expose']['label'] = 'License Status';
  $handler->display->display_options['filters']['status_2']['expose']['operator'] = 'status_2_op';
  $handler->display->display_options['filters']['status_2']['expose']['identifier'] = 'status_2';
  $handler->display->display_options['filters']['status_2']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Commerce License Billing Cycle: Status */
  $handler->display->display_options['filters']['status_3']['id'] = 'status_3';
  $handler->display->display_options['filters']['status_3']['table'] = 'cl_billing_cycle';
  $handler->display->display_options['filters']['status_3']['field'] = 'status';
  $handler->display->display_options['filters']['status_3']['relationship'] = 'cl_billing_cycle_target_id';
  $handler->display->display_options['filters']['status_3']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status_3']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status_3']['expose']['label'] = 'Recurring Status';
  $handler->display->display_options['filters']['status_3']['expose']['operator'] = 'status_3_op';
  $handler->display->display_options['filters']['status_3']['expose']['identifier'] = 'status_3';
  $handler->display->display_options['filters']['status_3']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['status_3']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    11 => 0,
    7 => 0,
    13 => 0,
    5 => 0,
    4 => 0,
    12 => 0,
    8 => 0,
    6 => 0,
    10 => 0,
    9 => 0,
  );

  /* Display: Recurring Order Management */
  $handler = $view->new_display('page', 'Recurring Order Management', 'page_1');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Displaying @start - @end of @total Total Recurring Orders';
  $handler->display->display_options['path'] = 'admin/commerce/orders/recurring';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Recurring Orders';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['blueoi_commerce_recurring_orders'] = array(
    t('Master'),
    t('Recurring Order Management'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('No results match your search.'),
    t('Drupal User'),
    t('Line items'),
    t('License'),
    t('Billing Cycle'),
    t('License Assigned'),
    t('Commerce Card on File'),
    t('Commerce Order'),
    t('- Choose an operation -'),
    t('Billing ID'),
    t('.'),
    t('Order ID'),
    t('Purchased By User'),
    t('Item'),
    t('Total'),
    t('Ends'),
    t('Order Status'),
    t('License Status'),
    t('Recurring Status'),
    t('Card Status'),
    t('<strong style="color:red">Bad Card</strong>'),
    t('Status'),
    t('Order status'),
    t('Expiration'),
    t('Displaying @start - @end of @total Total Recurring Orders'),
  );

  $views['blueoi_commerce_recurring_orders'] = $view;

  return $views;
}
