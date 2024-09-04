#pragma once
const int MAX_SURNAME = 255;
const int MAX_NAME = 255;
const int MAX_AUTHOR_LENGTH = 255;
const int MAX_YEAR_LENGTH = 10;
const int MAX_TEXT_LENGTH = 1000;

struct Song {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char year[MAX_YEAR_LENGTH];
    char text[MAX_TEXT_LENGTH];
};

Song catalog[MAX_SONGS];
int songCount = 0;