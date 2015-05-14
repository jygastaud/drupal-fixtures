<?php
function fixtures_drush_command() {
  $items = array();
  // Run all fixtures of all types
  $items['fixtures-all'] = array(
    'description' => 'Run all of the fixtures',
    'bootstrap' => 'DRUSH_BOOTSTRAP_DRUPAL_FULL',
    'callback' => 'fixtures_drush_create_all',
  );
  // Run all fixtures of user type
  $items['fixtures-user'] = array(
    'description' => 'Run users of the fixtures',
    'bootstrap' => 'DRUSH_BOOTSTRAP_DRUPAL_FULL',
    'callback' => 'fixtures_drush_create_users',
  );
  // Run all fixtures of node type
  $items['fixtures-nodes'] = array(
    'description' => 'Run nodes of the fixtures',
    'bootstrap' => 'DRUSH_BOOTSTRAP_DRUPAL_FULL',
    'callback' => 'fixtures_drush_create_nodes',
  );
  // Run all fixtures of menu type
  $items['fixtures-menus'] = array(
    'description' => 'Run menus of the fixtures',
    'bootstrap' => 'DRUSH_BOOTSTRAP_DRUPAL_FULL',
    'callback' => 'fixtures_drush_create_menus',
  );
  return $items;
}

function fixtures_drush_create_all() {
  // Import users
  fixtures_create_users();
  drush_log('Generated users from YAML files in "sites/all/fixtures"', 'success');
  // Import nodes
  fixtures_create_nodes();
  drush_log('Generated nodes from YAML files in "sites/all/fixtures"', 'success');
  // Import menu items
  fixtures_create_menus();
  drush_log('Generated menus from YAML files in "sites/all/fixtures"', 'success');
}

function fixtures_drush_create_users() {
  // Import users
  fixtures_create_users();
  drush_log('Generated users from YAML files in "sites/all/fixtures"', 'success');
}

function fixtures_drush_create_nodes() {
  // Import nodes
  fixtures_create_nodes();
  drush_log('Generated nodes from YAML files in "sites/all/fixtures"', 'success');
}

function fixtures_drush_create_menus() {
  // Import menu items
  fixtures_create_menus();
  drush_log('Generated menus from YAML files in "sites/all/fixtures"', 'success');
}
