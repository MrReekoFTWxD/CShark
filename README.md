# CShark [BETA]

### More Information
- [CShark - NextGenUpdate](http://www.nextgenupdate.com/forums/modern-warfare-3-mods-patches-tutorials/841800-cshark-beta.html "CShark")

### Development Team
- Justin ([Shark](http://www.nextgenupdate.com/forums/members/192112-shark.html "Shark")) - Lead Developer
- John ([John / FeverDEX](http://www.nextgenupdate.com/forums/members/896771-john.html "John")) - Co-Developer

### Credits
- Therifboy
- Momo5502
- NTAuthority
- icekobrin
- Anyone I Missed

### Features
- Call GSC Functions With Ease
- Get GSC/Notifies/Fields Return Values
- Set/Get Fields From Entities of All Class Types (Hud Elements, Players & Pathnodes)
- Make Use of Notifies Sent From The Game
- Ability To Send Notifies To The Game (Custom & Preset)
- Fairly Stable
- Good To Learn From

### Bugs
- Can't Call Things From Your Own Threads (With Stability Anyway)
- Can't Add Things That Requires Loops In VM_Notify (Unless You Can Find A Way To Make It Loop)
- Some Functions May Cause Overflows / Storage Overloads

### To Do
- Find a better way to handle threading, instead of hooking VM_Notify [ø]
- Add returns for CT_HUDELEM objects, atm only CT_ENTITY is supported (VAR_POINTER, for reference) [ ]
- Write A Complete Documentation On How To Use CShark Correctly & Effectively [ ]

### Changelog
~ [ Shark <---> 06/24/2015 ] ~
 - Developed a much cleaner way to call functions (using templates)
  - The compiler will then find the correct function which matches the correct amount
  of arguments being used, it will then use the Push template to detect each datatype
  of all the params, it will then seperate them accordingly into Scr_Add functions and
  automatically reverse the param order then CallRaw is called using the function address
  provided. (No need for PARAM_S structure anymore!)
  Returning is still a W.I.P

 - invoker.cpp removed, only invoker.h is needed due to how templates are handled in cpp
 - Old way to handle params redeveloped (explained above)
 - Virtual Threading added (handle.h, handle.cpp)
 - Reversed multipe Scr_Add + Scr_Get functions in order to find an efficient way to return GSC function values

~ [ Shark <---> 06/30/2015 ] ~
 - Developed Multiple Functions To Handle Different GSC Function Return Types
 - Made A Couple Of Bug Fixes
 - Added malloc and free Functions

~ [ Shark <---> 07/01/2015 ] ~
 - Added Namespace For Handling Entity Functions (Entity::Call(functionTable_t function, ...Args))
 - Stability Improvements
 - Added Function Table (functionTable_t)
 - Added Multiple Error Messages To Help Identify Simple Issues/Mistakes

~ [ Shark <---> 07/03/2015 ] ~
 - Redeveloped the way returns are handled, still needing to add support for other return types (Arrays, StringArrays, General Arrays)
 - Added A Function to clear out the call/return stack in order to improve stability (Also fixes "no memory allocated for script usage" error)
 - Updated the functionTable_t enum, some function indexes were wrong causing issues. 

~ [ Shark <---> 07/12/2015 ] ~
 - Redeveloped Printf, VSprintf etc, it now supports every type of value including floats (%g, %f etc)
 - Added Notify Functions, Notify("notifyString", args), OnNotify is W.I.P
 - Added A Way To Spawn Custom Server Threads //Being worked on still.
 - Stability Improvements
 - Added Entity Field Handling (getField, setField), along with a fieldTable and a way to get fieldOffsets
 - Developed better way to use constant strings (constStrings->value, is now just "value")
 - Added support for different classtypes (CT_ENTITY, CT_HUDELEM, CT_PATHNODE)
 - Various Bug Fixes (Not going into detail)
 - Fixed Entity Calls, now known as Object Calls (Object::), scr_entref_t was wrong, causing freezing/crashing

~ [ Shark <---> 07/12/2015 ] ~
 - Finalized The OnNotify function, can now be used to grab returns from any notify
 - Fixed Minor Bugs With Allocated Memory Issues
 - Fixed Crashing Issue (Another Compiler Problem)
 - Fixed Some Errors In Structures & Tables

~ [ Shark <---> 08/12/2015 ] ~
- Improved Support For HUD Elements
- Made It Easier To Work With Multiple Types
- Added Some New Functions
- Minor Bug Fixes
- Added More Return/Push Types
- Fixed Build Errors

~ [ Shark <---> 08/15/2015 ] ~
- Fixed An Issue With iPrintLn(Bold) & Similar Functions Freezing
- OnNotify No Longer Needs ParamCount Defined Manually
- OnNotify Now Supports entNum & classnum comparison
- Multiple Classnum Support Now Added To Every Call/Notify Function

~ [ Shark <---> 08/23/2015 ] ~
- Added The Ability To setField arrays/string arrays
- Reduced compiled prx/sprx size significantly
- Added New functions to support new setField/getField
- Added functions to push values locally ( LocalPush<variableType>(variableType value) )
