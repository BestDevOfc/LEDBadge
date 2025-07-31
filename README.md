*See https://github.com/crand6/RII-Badge for the files and context I had during this venture.*

<img width="1024" height="1024" alt="ChatGPT Image Jul 31, 2025, 01_55_22 AM" src="https://github.com/user-attachments/assets/64c51728-e555-400b-a529-997a76bd3515" />


# LED Patterns for a PCB Badge!
Full disclosure, this is my first ever time working with embedded; never even used an Arduino or RasPI before. 

The folks at RII chose this specific microchip, the 8-bit PIC16, because of its **obscure architecture and limitations**. Some others at the conference were able to unlock a special pattern by 
reverse engineering the pre-installed code, but I opted for the **interesting** dev challenge of making my own pattern!

I use "interesting" instead of "eye-opening" and "grateful for hardware engineers making tech better than a floppy disk."
This chip can only hold *512 12-bit words* of program memory and *25 8-bit words* of data. And only 1 working register!

## How to load the programs
This is my setup for transferring code to the PIC16. 
- MPLAB X IDE v6.20 (XC8 compiler since I'm coding in C)
    - Use the provided main file from the RII repo at the top.
    - To test if you have enough space, try Build Main Project.
    - **BEFORE YOU UPLOAD**, go to Project Settings > PICkit3 > Power and set it to 3.75V. (The manual for the chip says 5V though, but I'm not sure.)
    - When you're ready, attach the PICkit3 and press the big download button labelled "Make and Program Device Main Project" 
- A PICkit3 and 5 jumper cables
    - The pinouts on the chip and PICkit are mismatched. Read the labels on both to connect the jumpers.

## The Day Of
I signed up for the challenge and INSTANTLY wanted to make snake on this thing. The problem with that instantly revealed itself as a single integer took up 1/3 of all my data. I'd never worked with
shorts, because "Why? I have GIGAbytes". After optimizing every instruction and byte I could, I was left devastated with a compiler error "Can't find space for 0x11 bytes (maximum in text2 is 0x10)". 
Trying to cram some last-minute fixes before the big competition for bragging rights and lefts *yes those were the prizes*, the badge crashes after a random lightshow. 

But, I was left inspired, and bought a PICkit3 to continue programming it at home!
This repo is the collection of the patterns I've made since.
