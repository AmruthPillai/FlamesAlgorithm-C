# Flames Algorithm

**Step 1: ReadName Procedure**  
  1. Read two strings from the user and store it in `yourName` & `partnerName`, respectively  
  2. Remove spaces from both strings, if any  
  3. Convert both strings to lowercase (or uppercase)  
  4. Calculate the length of both strings and store in `yourNameLength` & `partnerNameLength` respectively  
	
**Step 2: EliminateCommonCharacters Procedure**  
  1. `FOR` `i` in every character in `yourName` till `yourNameLength`  
    1. `FOR` `j` in every character in `partnerName` till `partnerNameLength`  
      1. `IF` a character `yourName[i]` is equal to a character in `partnerName[j]` `THEN`  
        1. Remove the character from the strings `yourName` and `partnerName`  
        2. Break the inner loop as soon as a match is found, otherwise all instances of that character will be deleted  
      2. `END IF`
    2. `END FOR`  
  2. `END FOR`  
  3. Concatenate both strings and store it in `completeName` and calculate the length of it to be stored in `completeNameLength`  
	
**Step 3: FlamesCalculation Procedure**  
  1. Declare a string "FLAMES" with the variable `FLAMES` and store it's length of 6 in a variable `flamesLength`  
  2. Declare a variable `index` to store the index of the character to be striked out  
  3. WHILE length of `FLAMES` is not equal to 1, do the following:  
    1. `index <- completeNameLength % flamesLength`  
    2. `IF` (index == 0) `THEN`  
      3. Remove the last character of `FLAMES`  
    4. `ELSE`  
      5. Remove the character that `index` is currently pointing toward in `FLAMES`  
      6. Extract a substring of `FLAMES` from `(index) to end`, and another substring from `start to (index)`. Concatenate the two substrings and overwrite `FLAMES`  
    5. `END IF`  
    6. Decrement `flamesLength` by 1  
  4. `END WHILE`  
  5. At the end of the WHILE loop, the prediction will be the last remaining character of the `FLAMES`, which we will store in `flamesResult`  
	
**Step 4: DisplayResult Procedure**  
  1. `IF` `flamesResult` is  
    1. `F`, `THEN`  
      display "`yourName` & `partnerName` are friends!"  
    2. `L`, `THEN`  
      display "`yourName` & `partnerName` are lovers!"  
    2. `A`, `THEN`  
      display "`yourName` & `partnerName` are affectionate to each other!"  
    2. `M`, `THEN`  
      display "`yourName` & `partnerName` are or will be married!"  
    2. `E`, `THEN`  
      display "`yourName` & `partnerName` are enemies!"  
    2. `S`, `THEN`  
    display "`yourName` & `partnerName` are or are like siblings!"  
	2. `END IF`  
