/*! \file choice.h
    \brief Declaration of input handling and whitelist functions
    \author Alessandro Passaggio - Gregorio Bertelli
*/

#ifndef CHOICE_H
#define CHOICE_H

#include <iostream>

#define MAX_IN_LENGHT 10000
#define YN_WHITELIST_LENGHT 4
#define YN_WHITELIST_CHOICES 2
#define TD_WHITELIST_LENGHT 4
#define TD_WHITELIST_CHOICES 2
#define SH_WHITELIST_LENGHT 6
#define SH_WHITELIST_CHOICES 3
#define MN_WHITELIST_LENGHT 7
#define MN_WHITELIST_CHOICES 7

using namespace std;

/// @name WHITELISTS
/// @{
const string YNWhitelist[YN_WHITELIST_LENGHT] = {"y", "n", "Y", "N"};                   //yes e no
const string TDWhitelist[TD_WHITELIST_LENGHT] = {"t", "d", "T", "D"};                   //text e dimension
const string SHWhitelist[SH_WHITELIST_LENGHT] = {"a", "b", "c", "A", "B", "C"};         //shapes
const string MNWhitelist[MN_WHITELIST_LENGHT] = {"0", "1", "2", "3", "4", "5", "6"};    //menu 
/// @}

/// @name INPUT HANDLING FUNCTIONS
/// @{
int ChoiceCheck(string question, const string whiteList[], int lenght, int nchoices);
int PolygonSelection(string question, int dim);
float EnterDim(string question);
/// @}

#endif