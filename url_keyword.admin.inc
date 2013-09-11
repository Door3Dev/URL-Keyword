<?php

/**
 * Form definition
 */

function url_keyword_admin_form($form, &$form_state) {
  $form = array();
  $form['create_keyword'] = array(
  '#access' => user_access('administer menu'),
  '#markup' => l('Add a keyword', 'admin/door3/url_keyword/create', $options = array()),
  );
  $form['url_keyword_keywords'] = array(
    '#type' => 'item',
    '#title' => t('Current Keywords'),
  );
  $form['current_keywords'] = array(
  '#tree' => TRUE,
  '#theme' => 'table',
  '#header' => array(t('kwid'), t('keyword'), t('Page Title'), t('h1')),
  '#rows' => url_keyword_form_submissions(),
  );

  return system_settings_form($form);
}

function url_keyword_create_form($form, &$form_state) {
  $form = array();

  $form['back_keyword_list'] = array(
  '#access' => user_access('administer menu'),
  '#markup' => l('Keyword List', 'admin/door3/url_keyword', $options = array()),
  );
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
    '#value' => 'Create',
    '#submit' => array('url_keyword_create_form_submit'),
  );

  return system_settings_form($form);;
}

function url_keyword_create_form_validate($form, &$form_state) {
 // custom validation
}

function url_keyword_create_form_submit($form, &$form_state) {
  $db = 'url_keyword';
  $data = array(
    'keyword' => $form['keyword']['#value'],
    'page_title' => $form['page_title']['#value'],
    'h1' => $form['h1']['#value']
    );

  drupal_write_record($db, $data);
}

function url_keyword_form_submissions() {
    $query = db_select('url_keyword', 'uk');
    $query->fields('uk', array('kwid','keyword','page_title','h1'))
          ->range(0,50)
          ->orderBy('kwid');
    $results = $query->execute();
    $row = array();

    foreach($results as $result) {
      $row[] = array(
        $result->kwid,
        $result->keyword,
        $result->page_title,
        $result->h1,
       );
    }
    return $row;
}
