# TavernlightGamesAssessment

My revisions of Q1 - Q4 are completed. I took a C++ approach to Q1 and Q2, but revised Q3 with Lua in mind.
For Q4, I made additions to fix the memory leak and added comments as well.




When going through environment setup for Forgotten Server and OTClient there were a few roadblocks that needed to be solved:
Forgotten Server:
1. Instruced to download mysql-client but this did not pass the FindMySQL.cmake check. Instead, mysql library needed to be installed.
2. The latest version of fmt 10.2.1 library caused problems when building ForgottenServer 1.4. Because the task was to specifically use version 1.4 of Forgotten Server, I decided to manually build and install fmt 8.0.1 since this was the latest version of fmt when ForgottenServer 1.4 was created (September 2021).

OTClient:
1. Instructions advise to install Lua 5.1 but this formula is disabled by Homebrew. To get around this, I needed to edit the lua@5.1 formula and remove the line which disables installation after a specified date.