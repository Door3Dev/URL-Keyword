<?php 

/**
 * Form definition
 */

function url_keyword_admin_form($form, &$form_state) {
  $form = array();
  $form['url_keyword_page_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Keyword'),
    '#default_value' => variable_get('url_keyword_page_url', KEYWORD_DEFAULT_PAGE_URL),
    '#required' => TRUE,
  );

    $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Create'
  );

  $form['url_keyword_keywords'] = array(
    '#type' => 'item',
    '#title' => t('Current Keywords'),
    '#value' => 'list of existing keywords',
  );
  
  return system_settings_form($form);;
}

function url_keyword_create_form($form, &$form_state) {
  $form = array();
  $form['keyword'] = array(
    '#type' => 'textfield',
    '#title' => t('Keyword'),
    '#required' => TRUE,
  );
  $form['page_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Page Title'),
    '#required' => TRUE,
  );
  $form['h1'] = array(
    '#type' => 'textfield',
    '#title' => t('H1 Headline'),
    '#required' => TRUE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save'
  );

  return system_settings_form($form);;
}
function url_keyword_create_form_validate($form, &$form_state) {
  // validate as needed
}
function url_keyword_create_form_submit($form, &$form_state) {
  // use drupal_write_record to add it to your schema

}
