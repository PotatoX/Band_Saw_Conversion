# Band_Saw_Conversion

## Summary
<img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Pictures/20180805_144302.jpg" width="50%" height="50%">

Recently I needed (had an excuse to get) a band saw capable of cutting metal for a few of my projects. As with most of my projects/hobbies there are a number of outcomes I seek:

* Cheap
* Technical
* Build
* Learn

To this end I started shopping around to acquire a band saw as cheap as possible as it would only be used on a limited basis for hobby work. I need the saw to be able to cut metal and fit a small foot print on my bench. I wanted the saw to be vertical in order to minimize the space consumed as my bench and garage space is at a premium at this point.

With these constraints in mind I set my sights on a Harbor Freight 1/3 HP 9 in Benchtop Band Saw. I caught it on sale a Harbor Freight (w/ coupon) for right around $100. Similar saws can be found at your local big box stores.

Using this basic frame and some upgrades I have been able to convert this wood cutting vertical band saw to a metal cutting type with speed control and FPS display.

I now have a small band saw capable of cutting metal, wood, plastic, etc. that fits on the corner of my bench.

This project encompass the conversion and in indented to share the process with other makers. If you have questions, need additional details, or see any bugs please let me know.

The entire project can be found on [GitHub](https://github.com/PotatoX/Band_Saw_Conversion/). Consider contributing and making it even better if you happen to create other customizations.

Additionally, I will list parts used in this project on my [OpenBazzar store](https://openbazaar.com/store/QmVFRGwApdcef56Be7FPXnXQaB79rYrve3otFsrWvSwbAu).

## Design Choices
Thnking ack thrpugh the steps taken from the begining to end; a text book design process was not followed, rather a development and refine!emt from blade to display.

### The Blade
There the first choice was to find a blade that fit and was capable of cutting metalss (steel). By default the saw comes equiped woth a wood cutting 62in blade, carbon steel, 7 Teeth per Inch (*TPI*), 1/8in wide. I had found a couple of reports online that indicate success cutting plastic and aluminium, so long as a gentle touch was used. clearly the default blade had no chance of taking on steels.

Therefore the search began for a suitable bimetal blade. Most of my local stores carried various blades, some bimetal, but none in the 62in size. 62in appears to be a bit of a *custom* size. when local stores fail Amazon.com often saves the day. After scrolling though lists of blades I was able to to find a suitable blade; 62in, bimetal, 1/2in, 14 TPI.

[Imachinist S621214 62-inch X 1/2-inch X 14 TPI Bi-metal Band Saw Blades](https://www.amazon.com/gp/product/B010G9IJG6)

<img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Pictures/91MzAdiISML._SL1500_.jpg" width="20%" height="20%">

The next challenge was to find a way to drive the blade @ ~300 FPM for Steel, 600ish FPM for Aluminum, and 2000 FPM for Wood. Looking at the stock motor it was designed to drive the blade at 2460 FPM and is not adjustable. Further the motor is an induction motor which can not be speed controlled without a frequency drive, and even with one, would loose power proportional to the reduction in frequency; meaning at slow speeds is would lose power.

<img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Pictures/20180827_052338.jpg" width="20%" height="20%">

<img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Pictures/20180805_145138.jpg" width="20%" height="20%">

Therefore, a SCR controlled DC motor setup was needed. Given the *Cheap* requirement I scrubed ebay for a cheap DC motor. I found that used DC motors from tredmills seem to be abundent and are therefore reasonably priced. I found mine for ~$30.

<img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Pictures/ebay.jpg">

A small bracket had to be made to adapat the motor to the band saw frame

<img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Pictures/Motor Mount Assembly.png" width="20%" height="20%">

<img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Pictures/Motor Spacer.png" width="20%" height="20%">

In order to control the motor I found a generic SCR speed control. The exact feature of the SCR were not necessary to specify other than it needed to be able to handle sufficient power. 4000W was probably over kill, but rather more than not enough, and given the price for smaller units was roughly the same, this did the trick.

<img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Pictures/AC-220V-4000W-High-Power-SCR-Speed-Controller-Electronic-Voltage-Regulator-Governor-20-18L (4).jpg" width="20%" height="20%">

The SCR needed a couple of mods to fine tune the upper and lower speed bounds. This is expanded on more in in the electronics section.

In order to install the motor I had a to get small belt pully mate to the motor.

<img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Pictures/XL-12-Teeth-7mm-Aluminum-Bore-Timing-Belt-Idler-Pulley-Flange-Synchronous-Wheel-for-10mm.jpg" width="20%" height="20%">

I then needed an clean way to mount the SCR on the frame which led to the need to design an enclosure to house and mount the SCR.

I figured, if I am going to make a custom enclosure might as well make a display to disply the FPM of the blade; I mean I've come this far, why not.

<img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Pictures/Controller Assembly.png" width="20%" height="20%">

Lastely I designed a small board which reads a hall sensor on the back of the motor, then converts the motor shaft speed to FPM, and displays this on a small 7-Segment output. 

<img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Pictures/20180802_165257.jpg" width="20%" height="20%">

<img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Pictures/20180802_165301.jpg" width="20%" height="20%">

## The Physical Form

### Hardware
The enclosure has been modeled in Onshape, source files can be found [here](https://cad.onshape.com/documents/ca0881e1177c075414a017b7/w/e514d8a98751ae0bca0296ff/e/90af0d38bd02678226dfc615).

<img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Hardware/Models/Model 1.jpg" width="20%" height="20%"><img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Hardware/Models/Model 2.jpg" width="20%" height="20%"><img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Hardware/Models/Model 3.jpg" width="20%" height="20%"><img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Hardware/Models/Model 4.jpg" width="20%" height="20%"><img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Hardware/Models/Model 5.jpg" width="20%" height="20%"><img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Hardware/Models/Model 6.jpg" width="20%" height="20%"><img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Hardware/Models/Model 7.jpg" width="20%" height="20%"><img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Hardware/Models/Model 8.jpg" width="20%" height="20%"><img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Hardware/Models/Model 9.jpg" width="20%" height="20%"><img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Hardware/Models/Model 10.jpg" width="20%" height="20%"><img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Hardware/Models/Model 11.jpg" width="20%" height="20%"><img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Hardware/Models/Model 12.jpg" width="20%" height="20%"><img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Hardware/Models/Model 13.jpg" width="20%" height="20%">

If you are in need of a 3D printed enclosure, let me know and I will be happy to add them to my [OpenBazzar store](https://openbazaar.com/store/QmVFRGwApdcef56Be7FPXnXQaB79rYrve3otFsrWvSwbAu).

### Electronics

#### SCR Modifications
Unfortunately I forgot to take pictures while modifing the SCR. If you get a generic SCR you simply have to swap out the the potentiometer some one that is of a range more appropraite for the speeds you whish to operate at. This will be SCR and motor dependent. In my case I added a 33k resistor in series with a 50K pot.

#### Hall Effect Sensor
The hall effect sensor I used was an A3141 IC. This worked for my setup given the magnet I used and its location on the rear portion of the motor shaft. Any hall effect sensor in this family should do the trick.

[Datasheet](https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Electronics/KiCad/Tachometer/Datasheets/A3141-2-3-4-Datasheet.pdf)

#### Tachometer Board
The design has been complete in KiCad. Input either 120V AC or 6V-12V DC. Board can be but down to remove AC section if DC is used. I have excess boards that will be listed on my [OpenBazzar store](https://openbazaar.com/store/QmVFRGwApdcef56Be7FPXnXQaB79rYrve3otFsrWvSwbAu) along with some of the odd components.

<img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Electronics/KiCad/Tachometer/Publish/Tachometer.sch.svg" width="20%" height="20%">

<img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Electronics/KiCad/Tachometer/Publish/e889038e-7901-4f7f-9a18-62940a5edb01_1_0_1.png" width="20%" height="20%"> <img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Electronics/KiCad/Tachometer/Publish/e889038e-7901-4f7f-9a18-62940a5edb01_2_0_1.png" width="20%" height="20%">

<img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Electronics/KiCad/Tachometer/Publish/Binder1_Page_1.png" width="20%" height="20%"><img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Electronics/KiCad/Tachometer/Publish/Binder1_Page_2.png" width="20%" height="20%"><img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Electronics/KiCad/Tachometer/Publish/Binder1_Page_3.png" width="20%" height="20%"><img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Electronics/KiCad/Tachometer/Publish/Binder1_Page_4.png" width="20%" height="20%"><img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Electronics/KiCad/Tachometer/Publish/Binder1_Page_5.png" width="20%" height="20%"><img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Electronics/KiCad/Tachometer/Publish/Binder1_Page_6.png" width="20%" height="20%"><img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Electronics/KiCad/Tachometer/Publish/Binder1_Page_7.png" width="20%" height="20%">

<img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Electronics/KiCad/Tachometer/Publish/BOM.jpg" width="40%" height="40%">

If you need a component not currently listed, let me know and I will be happy to add them to my [OpenBazzar store](https://openbazaar.com/store/QmVFRGwApdcef56Be7FPXnXQaB79rYrve3otFsrWvSwbAu) along with some of the odd components..

### Software
[Arduino firmware can be found here.](https://github.com/PotatoX/Band_Saw_Conversion/tree/master/Software/Arduino/Tachometer_Rev_A)

#### Calculation of Slope
There are a couple of ways to calculate the correct [slope value](https://github.com/PotatoX/Band_Saw_Conversion/blob/c9c9d59a0e278d77ea138ab6ab9a776811436fa7/Software/Arduino/Tachometer_Rev_A/Tachometer_Rev_A.ino#L35) for the firmware:

##### Method 1 - Experimentation w/ Tachometer
This method requires a [contactless tachometer](https://www.aliexpress.com/item/2017-Hot-Selling-NEW-Digital-Laser-Photo-Tachometer-Non-Contact-RPM-Tach-Speed-Gauge-Engine-High/32827623720.html).

<img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Software/Arduino/Tachometer_Rev_A/Tachometer.jpg" width="20%" height="20%">

1. Initially set the slope to 1 and flash the controller.
2. Connect the controller board to the saw and verify proper operation
3. Measure the diameter of one of your blade drive wheels.
<img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Software/Arduino/Tachometer_Rev_A/Method1.jpg" width="10%" height="10%">

4. Place a tachometer reflector on the blade drive wheel and test that stable RPM readings can be taken. *Caution* as the cover to the saw is open in order to take this measurement take extream care to be as far away from the blade as possible, and allow yourself multiple options for escape and power shut off incase the blade should come off the drive wheels.
5. Start the band saw at a low speed and record both the reading on the controller and the reading on the tachometer.
6. Repeat measurements various times in order to take readings through out the intended operating speed range.
7. Using a [spreadsheet](https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Software/Arduino/Tachometer_Rev_A/BandSaw%20Slope%20Calculations.ods?raw=true) convert the tachometer readings to SFM
8. Using a [spreadsheet](https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Software/Arduino/Tachometer_Rev_A/BandSaw%20Slope%20Calculations.ods?raw=true) plot the controller readings vs the SFM(tachometer readings).
10. Generate a linear fit, note the slope of the fit equation.
11. Input the slope into the firmware of the controller and re-flash. The controller should now read in SFM.

##### Method 2 - Ratio Calculations
1. Measure the diameter of one of your blade drive wheels.
<img src="https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Software/Arduino/Tachometer_Rev_A/Method2.jpg" width="10%" height="10%">

2. Count the teeth of the motor pully and the blade wheel pully.
3. Enter the all values in the [spreadsheet](https://github.com/PotatoX/Band_Saw_Conversion/blob/master/Software/Arduino/Tachometer_Rev_A/BandSaw%20Slope%20Calculations.ods?raw=true).
4. Input the slope into the firmware of the controller and flash. The controller should now read in SFM.

# Support Projects Like This
You can support projects like this by using my [OpenBazzar store](https://openbazaar.com/store/QmVFRGwApdcef56Be7FPXnXQaB79rYrve3otFsrWvSwbAu). Like all hobbies, ones that are self-funded are always easier progress.

# Safety/Disclaimer
I am furnishing this item/content "as is". I do not provide any warranty of the item/content whatsoever, whether express, implied, or statutory, including, but not limited to, any warranty of merchantability or fitness for a particular purpose or any warranty that the contents of the item/content will be error-free.

In no respect shall I incur any liability for any damages, including, but limited to, direct, indirect, special, or consequential damages arising out of, resulting from, or any way connected to the use of the item, whether or not based upon warranty, contract, tort, or otherwise; whether or not injury was sustained by persons or property or otherwise; and whether or not loss was sustained from, or arose out of, the results of, the item/content, or any services that may be provided herein.
