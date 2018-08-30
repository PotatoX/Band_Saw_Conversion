# Band_Saw_Conversion

## Summary
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

### Electronics

#### SCR Modifications

#### Hall Effect Sensor

#### Tachometer Board

### Software

# Safety/Disclaimer
I am furnishing this item/content "as is". I do not does not provide any warranty of the item whatsoever, whether express, implied, or statutory, including, but not limited to, any warranty of merchantability or fitness for a particular purpose or any warranty that the contents of the item/content will be error-free.

In no respect shall I incur any liability for any damages, including, but limited to, direct, indirect, special, or consequential damages arising out of, resulting from, or any way connected to the use of the item, whether or not based upon warranty, contract, tort, or otherwise; whether or not injury was sustained by persons or property or otherwise; and whether or not loss was sustained from, or arose out of, the results of, the item/content, or any services that may be provided herein.
