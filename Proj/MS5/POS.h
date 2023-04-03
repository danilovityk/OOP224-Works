/*
 *         Name: Danylo Vityk
 *         Email: dvityk@myseneca.ca
 *         Sudent ID: 176326213
 *         Date: Mar 17, 2023
 *
 *
 *         I have done all the coding by myself and only copied the code that my professor provided to complete my workshops
 *         and assignments.
 *
 *
 */

#ifndef POS_H
#define POS_H

namespace sdds {

int const MAX_NAME_LEN = 40;

int const POS_LIST = 1;
int const POS_FORM = 2;

const char ERROR_POS_SKU[]   = "SKU too long";
const char ERROR_POS_NAME[]  = "Item name too long";
const char ERROR_POS_PRICE[] = "Invalid price value";
const char ERROR_POS_TAX[]   = "Invalid tax status";
const char ERROR_POS_QTY[]   = "Invalid quantity value";
const char ERROR_POS_STOCK[] = "Item out of stock";
const char ERROR_POS_EMPTY[] = "Invalid Empty Item";

double const TAX = 0.13;
int const MAX_SKU_LEN = 7;

int const MIN_YEAR = 2000;
int const MAX_YEAR = 2030;

int const MAX_STOCK_NUMBER = 99;
int const MAX_NO_ITEMS = 2000;

}

#endif
