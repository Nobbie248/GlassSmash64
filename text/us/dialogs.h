/**
 * DEFINE_DIALOG macro
 *    - Dialog enum ID (see dialog_ids.h)
 *    - Voice Sound (see sounds.h)
 *    - Lines per box
 *    - Left offset (Distance from left edge of the screen to dialog box)
 *    - Bottom offset (Distance from bottom of the screen to the top of the dialog box, SCREEN_HEIGHT would be the top)
 *    - Text
 * 
 * 
 * Control characters:
 *   Special text commands are supported, for functions such as custom text color.
 *   See "ingame_menu.h" for more details.
 * 
 * 
 * Special Characters:
 *   Here are some special characters you can use:
 *      Ⓐ
 *      Ⓑ
 *      Ⓒ
 *      Ⓩ
 *      Ⓡ
 *      “ and ” (left and right quotes)
 *      ◀▶▼▲
 *      ★ ✪
 *
 * 
 * See segment2.c LUTs for more info:
 *    - main_font_lut
 *    - main_hud_utf8_2byte_lut
 *    - main_hud_utf8_3byte_lut
 *    - main_hud_utf8_4byte_lut
 */

DEFINE_DIALOG(DIALOG_000,1,5,30,200, "")

DEFINE_DIALOG(DIALOG_001,1,4,95,200, "What? Just because I'm\n\
a bomb means I\n\
can't be the elder of\n\
Toad Taiga? Is that it?\n\
......\n\
......\n\
......\n\
......\n\
...Sorry if I was a bit\n\
explosive. I didn't mean\n\
to blow up on you. I have\n\
a bit of a short fuse.\n\
What's that? You want to\n\
get to the mountain's\n\
summit? Then listen\n\
closely.\n\
There is an ancient slide\n\
here in town known as\n\
the Snowman Slide. It's \n\
been inaccessible since \n\
Bowser wrecked the \n\
place, but with one more \n\
Power Star, you should\n\
be able to get there.\n\
Seek a picture of the\n\
great snowman's head\n\
and stand there (This \n\
only works on Star 5).\n\
Should you complete the\n\
slide successfully, you\n\
will learn the secret \n\
method by which ancient\n\
Toads used to climb to\n\
the Mountain's Summit\n\
long ago.\n\
\n\
Anyway, I imagine you'll \n\
be wanting a star for \n\
your trouble getting here.\n\
\n\
Stand directly behind\n\
my house and jump off\n\
of this mountain. Do \n\
some camera panning\n\
and a kick or something \n\
too - better to play it \n\
safe, right?\n\
\n\
Good luck!")

DEFINE_DIALOG(DIALOG_002,1,4,95,200, "")

DEFINE_DIALOG(DIALOG_003,1,5,30,200, "Thank you, Mario! The Big\n\
Bob-omb is nothing but a\n\
big dud now! But the\n\
battle for the castle has\n\
just begun.\n\
Other enemies are holding\n\
the other Power Stars. If\n\
you recover more Stars,\n\
you can open new doors\n\
that lead to new worlds!\n\
My Bob-omb Buddies are\n\
waiting for you. Be sure\n\
to talk to them--they'll\n\
set up cannons for you.")

DEFINE_DIALOG(DIALOG_004,1,3,95,200, "We're peace-loving\n\
Bob-ombs, so we don't use\n\
cannons.\n\
But if you'd like\n\
to blast off, we don't\n\
mind. Help yourself.\n\
We'll prepare all of the\n\
cannons in this course for\n\
you to use. Bon Voyage!")

DEFINE_DIALOG(DIALOG_005,1,5,30,200, "'Sup, player!\n\
Think you can keep your\n\
ass out of the lava long\n\
enough to race against\n\
me?\n\
I got bit by a spider and\n\
now I can walk on lava\n\
and run super fast. \n\
Pretty cool, huh?\n\
\n\
But don't worry, I put\n\
some elevators near the\n\
base of the volcano so \n\
that you have a shot at \n\
beating me.\n\
Heck, I bet you'll need\n\
that shell at the top of\n\
the volcano to win! Only\n\
pros can beat me without\n\
one.\n\
Ready?\n\
\n\
\n\
\n\
\n\
\n\
\tGo!\t\tDon't Go")

DEFINE_DIALOG(DIALOG_006,1,4,30,200, "So, you thought you\n\
could just use the cannon\n\
and I wouldn't notice,\n\
huh?\n\
Nice try, cheater, maybe\n\
next time if you feel like\n\
playing fair you can look\n\
me up.")

DEFINE_DIALOG(DIALOG_007,1,5,30,200, "Holy...cow...you are\n\
wicked fast! Even with \n\
my new found powers \n\
you still whooped me!\n\
\n\
I gotta go to the doctor\n\
anyway and get this\n\
spider bite checked out.\n\
I probably have cancer\n\
or something.\n\
I mean, walking up a \n\
lava falls is not normal, \n\
dude!")

DEFINE_DIALOG(DIALOG_008,1,4,30,200, "This pipe will take you\n\
back to Area 1 of this\n\
world. Your coin count\n\
will not be reset.\n\
This is a one way trip\n\
so don't expect to be\n\
able to just jump back\n\
here through the pipe.")

DEFINE_DIALOG(DIALOG_009,1,5,30,200, "Long time, no see! Wow,\n\
have you gotten fast!\n\
Have you been training\n\
on the sly, or is it the\n\
power of the Stars?\n\
I've been feeling down\n\
about losing the last\n\
race. This is my home\n\
course--how about a\n\
rematch?\n\
The goal is in\n\
Windswept Valley.\n\
Ready?\n\
\n\
\tGo\t\t Don't Go")

DEFINE_DIALOG(DIALOG_010,1,4,30,200, "You have found the only \n\
switch in the game. The\n\
Wing Cap is now yours\n\
to wield.\n\
\n\
Isn't that exciting?\n\
\n\
\tYes\t\tNo")

DEFINE_DIALOG(DIALOG_011,1,4,30,200, "You've just stepped on\n\
the Metal Cap Switch!\n\
The Metal Cap makes\n\
Mario invincible.\n\
Now Metal Caps will\n\
pop out of all of the\n\
green blocks you find.\n\
\n\
Would you like to Save?\n\
\n\
\tYes\t\tNo")

DEFINE_DIALOG(DIALOG_012,1,4,30,200, "You've just stepped on\n\
the Vanish Cap Switch.\n\
The Vanish Cap makes\n\
Mario disappear.\n\
Now Vanish Caps will pop\n\
from all of the blue\n\
blocks you find.\n\
\n\
Would you like to Save?\n\
\n\
\tYes\t\tNo")

DEFINE_DIALOG(DIALOG_013,1,5,30,200, "You did it!\n\
Would you like to restart?\n\
Progress will be saved.\n\
\tYes\t\tNo")

DEFINE_DIALOG(DIALOG_014,1,4,30,200, "Well done! Each star you \n\
collect brings you closer \n\
to recovering Princess \n\
Peach's crown.\n\
Do you want to Save?\n\
\n\
\tSure!\tNo, thanks.")

DEFINE_DIALOG(DIALOG_015,1,4,30,200, "You found a crown gem!\n\
Do you want to Save?\n\
\n\
\tSure!\tNo, thanks.")

DEFINE_DIALOG(DIALOG_016,1,3,30,200, "")

DEFINE_DIALOG(DIALOG_017,1,5,30,200, "I'm the Big Bob-omb, lord\n\
of all blasting matter,\n\
king of ka-booms the\n\
world over!\n\
How dare you scale my\n\
mountain? By what right\n\
do you set foot on my\n\
imperial mountaintop?\n\
You may have eluded my\n\
guards, but you'll never\n\
escape my grasp...\n\
\n\
...and you'll never take\n\
away my Power Star. I\n\
hereby challenge you,\n\
Mario!\n\
If you want the Star I\n\
hold, you must prove\n\
yourself in battle.\n\
\n\
Can you pick me up from\n\
the back and hurl me to\n\
this royal turf? I think\n\
that you cannot!")

DEFINE_DIALOG(DIALOG_018,1,5,30,200, "If you are smart about \n\
it, you can easily \n\
retrieve the star on the\n\
mountain's summit with\n\
the resources you have.\n\
NOTE: If you have not \n\
found and pressed the \n\
red Cap Switch yet, you \n\
will not be able to get \n\
this star.\n\
So, have you found the \n\
red Cap Switch yet, \n\
Mario? Maybe you should \n\
look around the Castle a \n\
little harder...")

DEFINE_DIALOG(DIALOG_019,1,2,30,200, "Shhh! Please walk\n\
quietly in the hallway!")

DEFINE_DIALOG(DIALOG_020,1,6,95,150, "Dear Mario:\n\
Please come to the\n\
castle. I've baked\n\
a cake for you.\n\
Yours truly--\n\
Princess Toadstool")

DEFINE_DIALOG(DIALOG_021,1,5,95,200, "Welcome.\n\
No one's home!\n\
Now scram--\n\
and don't come back!\n\
Gwa ha ha!")

DEFINE_DIALOG(DIALOG_022,1,2,95,200, "You need a key to open\n\
this door.")

DEFINE_DIALOG(DIALOG_023,1,3,95,200, "This key doesn't fit!\n\
Maybe it's for the\n\
basement...")

DEFINE_DIALOG(DIALOG_024,1,5,95,200, "You need Star power to\n\
open this door. Recover a\n\
Power Star from an enemy\n\
inside one of the castle's\n\
paintings.")

DEFINE_DIALOG(DIALOG_025,1,4,95,200, "It takes the power of\n\
3 Stars to open this\n\
door. You need %d more\n\
Stars.")

DEFINE_DIALOG(DIALOG_026,1,4,95,200, "It takes the power of\n\
8 Stars to open this\n\
door. You need %d more\n\
Stars.")

DEFINE_DIALOG(DIALOG_027,1,4,95,200, "You shall not pass\n\
without the power of 30\n\
Stars. You need %d more\n\
Stars.")

DEFINE_DIALOG(DIALOG_028,1,4,95,200, "It takes the power of\n\
50 Stars to open this\n\
door. You need %d more\n\
Stars.")

DEFINE_DIALOG(DIALOG_029,1,5,95,200, "To open the door that\n\
leads to the 『endless』\n\
stairs, you need 70\n\
Stars.\n\
Bwa ha ha!")

DEFINE_DIALOG(DIALOG_030,1,6,30,200, "Hello! The Lakitu Bros.,\n\
cutting in with a live\n\
update on Mario's\n\
progress. He's about to\n\
learn a technique for\n\
sneaking up on enemies.\n\
The trick is this: He has\n\
to walk very slowly in\n\
order to walk quietly.\n\
\n\
\n\
\n\
And wrapping up filming\n\
techniques reported on\n\
earlier, you can take a\n\
look around using Ⓒ▶ and\n\
Ⓒ◀. Press Ⓒ▼ to view the\n\
action from a distance.\n\
When you can't move the\n\
camera any farther, the\n\
buzzer will sound. This is\n\
the Lakitu Bros.,\n\
signing off.")

DEFINE_DIALOG(DIALOG_031,1,5,30,200, "No way! You beat me...\n\
again!! And I just spent\n\
my entire savings on\n\
these new Koopa\n\
Mach 1 Sprint shoes!\n\
Here, I guess I have to\n\
hand over this Star to\n\
the winner of the race.\n\
Congrats, Mario!")

DEFINE_DIALOG(DIALOG_032,1,5,30,200, "Come back here for\n\
Star 6.")

DEFINE_DIALOG(DIALOG_033,1,6,30,200, "Ciao! You've reached\n\
Princess Toadstool's\n\
castle via a warp pipe.\n\
Using the controller is a\n\
piece of cake. Press Ⓐ  to\n\
jump and Ⓑ to attack.\n\
Press Ⓑ to read signs,\n\
too. Use the Control Stick\n\
in the center of the\n\
controller to move Mario\n\
around. Now, head for\n\
the castle.")

DEFINE_DIALOG(DIALOG_034,1,6,30,200, "Good afternoon. The\n\
Lakitu Bros., here,\n\
reporting live from just\n\
outside the Princess's\n\
castle.\n\
\n\
Mario has just arrived\n\
on the scene, and we'll\n\
be filming the action live\n\
as he enters the castle\n\
and pursues the missing\n\
Power Stars.\n\
As seasoned cameramen,\n\
we'll be shooting from the\n\
recommended angle, but\n\
you can change the\n\
camera angle by pressing\n\
the [C] Buttons.\n\
If we can't adjust the\n\
view any further, we'll\n\
buzz. To take a look at\n\
the surroundings, stop\n\
and press [C]^.\n\
\n\
Press Ⓐ  to resume play.\n\
Switch camera modes with\n\
the [R] Button. Signs along\n\
the way will review these\n\
instructions.\n\
\n\
For now, reporting live,\n\
this has been the\n\
Lakitu Bros.")

DEFINE_DIALOG(DIALOG_035,1,4,30,200, "Come back here on\n\
Star 5.")

DEFINE_DIALOG(DIALOG_036,1,3,30,200, "What do you get when\n\
you cross a Chain Chomp\n\
with a Long Jump?")

DEFINE_DIALOG(DIALOG_037,1,2,30,200, "I win! You lose!\n\
Ha ha ha ha!\n\
You're no slouch, but I'm\n\
a better sledder!\n\
Better luck next time!")

DEFINE_DIALOG(DIALOG_038,1,3,95,200, "Reacting to the Star\n\
power, the door slowly\n\
opens.")

DEFINE_DIALOG(DIALOG_039,1,4,30,200, "No visitors allowed,\n\
by decree of\n\
the Big Bob-omb\n\
\n\
I shall never surrender my\n\
Stars, for they hold the\n\
power of the castle in\n\
their glow.\n\
They were a gift from\n\
Bowser, the Koopa King\n\
himself, and they lie well\n\
hidden within my realm.\n\
Not a whisper of their\n\
whereabouts shall leave\n\
my lips. Oh, all right,\n\
perhaps one hint:\n\
Heed the Star names at\n\
the beginning of the\n\
course.\n\
\t--The Big Bob-omb")

DEFINE_DIALOG(DIALOG_040,1,3,30,200, "Warning!\n\
Cold, Cold Crevasse\n\
Below!")

DEFINE_DIALOG(DIALOG_041,1,5,30,200, "I've seen some racing in\n\
my time, but that was \n\
the shittest, crappest, \n\
crappiest, shittiest,\n\
racing I've ever seen.\n\
Yeah, that was pretty\n\
crap. As good racing \n\
goes, it was abysmal.\n\
\n\
\n\
Anyway, look me up if\n\
you wanna try again.\n\
It's so hard to find good\n\
competition these days.")

DEFINE_DIALOG(DIALOG_042,1,4,30,200, "Hi Mario!\n\
It's the mayor's day off\n\
today. You won't find\n\
him upstairs.\n\
He's still expecting you \n\
to find 8 red coins in \n\
exchange for use of our \n\
box storage, though.\n\
Best of luck hunting \n\
them down!")

DEFINE_DIALOG(DIALOG_043,1,5,30,200, "Thanks for the red coins,\n\
Mario! As promised, I\n\
had my team place\n\
ladders leading further \n\
up the mountain. \n\
Why don't you climb up \n\
there and see if you can \n\
find the Elder? We have\n\
not seen him in quite\n\
some time.\n\
By the way, you know\n\
that tree up on the cliff?\n\
Just climb back up\n\
there, we created a\n\
shortcut for you.")

DEFINE_DIALOG(DIALOG_044,1,5,95,200, "Having trouble figuring\n\
out how to get to the\n\
slide? Just stand in the\n\
center of town on top\n\
of the snowman face!")

DEFINE_DIALOG(DIALOG_045,1,6,95,200, "It's all up to you now,\n\
Mario! You have all the\n\
necessary tools at your\n\
disposal. A wing cap, a\n\
cannon...do you see what\n\
I'm saying?")

DEFINE_DIALOG(DIALOG_046,1,5,30,200, "You have to master three\n\
important jumping\n\
techniques.\n\
First try the Triple Jump.\n\
\n\
Run fast, then jump three\n\
times, one, two, three.\n\
If you time the jumps\n\
right, you'll hop, skip,\n\
then jump really high.\n\
Next, go for distance\n\
with the Long Jump. Run,\n\
press Ⓩ to crouch then Ⓐ \n\
to jump really far.\n\
\n\
To do the Wall Kick, press\n\
Ⓐ  to jump at a wall, then\n\
jump again when you hit\n\
the wall.\n\
\n\
Got that? Triple Jump,\n\
Long Jump, Wall Kick.\n\
Practice, practice,\n\
practice. You don't stand\n\
a chance without them.")

DEFINE_DIALOG(DIALOG_047,1,2,95,200, "Hi! I'll prepare the\n\
cannon for you!")

DEFINE_DIALOG(DIALOG_048,1,4,30,200, "Snow Mountain Summit\n\
Watch for slippery\n\
conditions! Please enter\n\
the cottage first.")

DEFINE_DIALOG(DIALOG_049,1,3,30,200, "Welcome to Tartaruga\n\
Castle. Please enjoy \n\
your stay.\n\
Heh heh heh...guess who?\n\
\n\
\n\
That's right. It's Bowser.\n\
\n\
\n\
If you're here, you\n\
probably already know\n\
that I've stolen Peach's\n\
crown. And with its\n\
mystical powers, I will\n\
soon regain control of\n\
the Mushroom Kingdom.\n\
BWA HA HA!\n\
\n\
I'll give you a chance to\n\
get it back, just visit me\n\
with the 30 stars from\n\
the 4 worlds in this\n\
castle. Tread carefully,\n\
my Italian friend.\n\
BWA HA HA HAAA!")

DEFINE_DIALOG(DIALOG_050,1,5,30,200, "If you ever see something\n\
that looks like me, it's\n\
probably a good sign\n\
that you should start\n\
reading.")

DEFINE_DIALOG(DIALOG_051,1,6,30,200, "Climbing's easy! When you\n\
jump at trees, poles or\n\
pillars, you'll grab them\n\
automatically. Press Ⓐ  to\n\
jump off backward.\n\
\n\
To rotate around the\n\
object, press Right or\n\
Left on the Control Stick.\n\
When you reach the top,\n\
press Up to do a\n\
handstand!\n\
Jump off from the\n\
handstand for a high,\n\
stylin' dismount.")

DEFINE_DIALOG(DIALOG_052,1,5,30,200, "Stop and press Ⓩ to\n\
crouch, then press Ⓐ \n\
to do a high, Backward\n\
Somersault!\n\
\n\
To perform a Side\n\
Somersault, run, do a\n\
sharp U-turn and jump.\n\
You can catch lots of\n\
air with both jumps.")

DEFINE_DIALOG(DIALOG_053,1,5,30,200, "This space is a one-way\n\
warp back to the start.\n\
You will not be able to\n\
return back here until\n\
you restart the level.\n\
Having trouble with the\n\
pillars? Try longjumping\n\
into the tallest one from \n\
one of the shorter ones,\n\
then walljumping off its\n\
side to reach the second\n\
tallest one. It takes some\n\
practice, but it can be\n\
done!")

DEFINE_DIALOG(DIALOG_054,1,5,30,200, "Instead of trying to \n\
walljump back out of\n\
here, why not use the\n\
handy fading warp on\n\
the pad to the right?")

DEFINE_DIALOG(DIALOG_055,1,4,30,200, "Hey-ey, Mario, buddy,\n\
howzit goin'? Step right\n\
up. You look like a fast\n\
sleddin' kind of guy.\n\
I know speed when I see\n\
it, yes siree--I'm the\n\
world champion sledder,\n\
you know. Whaddya say?\n\
How about a race?\n\
Ready...\n\
\n\
\tGo\t\t Don't Go")

DEFINE_DIALOG(DIALOG_056,1,6,30,200, "You brrrr-oke my record!\n\
Unbelievable! I knew\n\
that you were the coolest.\n\
Now you've proven\n\
that you're also the\n\
fastest!\n\
I can't award you a gold\n\
medal, but here, take this\n\
Star instead. You've\n\
earned it!")

DEFINE_DIALOG(DIALOG_057,1,4,30,200, "Egad! My baby!! Have you\n\
seen my baby??? She's\n\
the most precious baby in\n\
the whole wide world.\n\
(They say she has my\n\
beak...) I just can't\n\
remember where I left\n\
her.\n\
Let's see...I stopped\n\
for herring and ice cubes,\n\
then I...oohh! I just\n\
don't know!")

DEFINE_DIALOG(DIALOG_058,1,4,30,200, "You found my precious,\n\
precious baby! Where\n\
have you been? How can\n\
I ever thank you, Mario?\n\
Oh, I do have this...\n\
...Star. Here, take it\n\
with my eternal\n\
gratitude.")

DEFINE_DIALOG(DIALOG_059,1,4,30,200, "That's not my baby! She\n\
looks nothing like me!\n\
Her parents must be\n\
worried sick!")

DEFINE_DIALOG(DIALOG_060,1,4,30,200, "Fun fact: A taiga is a\n\
snowy, sometimes \n\
mountainous, forest\n\
biome.")

DEFINE_DIALOG(DIALOG_061,1,5,30,200, "If you've ever had the\n\
thought 『how do I do\n\
this goddamn thing?!』\n\
then this is the sign for\n\
you!\n\
Camera setup: this is all\n\
on an axis so use Lakitu\n\
cam and pretend it's a\n\
2D environment. Watch\n\
Mario through the glass.\n\
Upon entering the glass\n\
box, slide down the first\n\
slide and jump before\n\
the slide ends. Go into \n\
about 5 wallkicks before\n\
landing on the next slide\n\
up, which takes you in\n\
the opposite direction.\n\
\n\
\n\
Repeat this step again,\n\
and on the last slide, \n\
you'll do the same jump\n\
and wall kicks and that\n\
will take you to the top\n\
section of the Pachinko\n\
Machine.\n\
\n\
\n\
\n\
From the top, the only\n\
way you can go is a drop\n\
down into the maze\n\
section. Zoom your\n\
camera out and pay\n\
close attention: it is\n\
possible to fall out near \n\
the end and to have to\n\
start from the beginning.")

DEFINE_DIALOG(DIALOG_062,1,3,30,200, "Uh huh...thought you\n\
could cheese it, huh?\n\
\n\
Stand on top of me\n\
to return to the rainbow\n\
path.")

DEFINE_DIALOG(DIALOG_063,1,5,30,200, "The Vanish Cap is inside\n\
the blue block. Mr. I.\n\
will be surprised, since\n\
you'll be invisible when\n\
you wear it!\n\
Even the Big Boo will be\n\
fooled--and you can walk\n\
through secret walls, too.")

DEFINE_DIALOG(DIALOG_064,1,6,30,200, "This 1-Up\n\
commemorates Ap616,\n\
who was the first to\n\
reach the peak of these\n\
lava falls.\n\
\n\
Experts say he was \n\
disappointed that he was\n\
not rewarded for his\n\
exploration, as finding a\n\
difficult to reach area\n\
typically results in a \n\
reward of some kind. As\n\
a result, 2 Paratroopas \n\
were sent from corporate\n\
to plant this platform \n\
and 1-Up in his honor.")

DEFINE_DIALOG(DIALOG_065,1,6,30,200, "")

DEFINE_DIALOG(DIALOG_066,1,5,30,200, "Mario, it's Peach!\n\
Please be careful! Bowser\n\
is so wicked! He will try\n\
to burn you with his\n\
horrible flame breath.\n\
Run around behind and\n\
grab him by the tail with\n\
the Ⓑ Button. Once you\n\
grab hold, swing him\n\
around in great circles.\n\
Rotate the Control Stick\n\
to go faster and faster.\n\
The faster you swing him,\n\
the farther he'll fly.\n\
\n\
Use the [C] Buttons to look\n\
around, Mario. You have\n\
to throw Bowser into one\n\
of the bombs in the four\n\
corners.\n\
Aim well, then press Ⓑ\n\
again to launch Bowser.\n\
Good luck, Mario! Our\n\
fate is in your hands.")

DEFINE_DIALOG(DIALOG_067,1,5,30,200, "Tough luck, Mario!\n\
Princess Toadstool isn't\n\
here...Gwa ha ha!! Go\n\
ahead--just try to grab\n\
me by the tail!\n\
You'll never be able to\n\
swing ME around! A wimp\n\
like you won't throw me\n\
out of here! Never! Ha!")

DEFINE_DIALOG(DIALOG_068,1,5,30,200, "It's Lethal Lava Land!\n\
If you catch fire or fall\n\
into a pool of flames,\n\
you'll be hopping mad, but\n\
don't lose your cool.\n\
You can still control\n\
Mario--just try to keep\n\
calm!")

DEFINE_DIALOG(DIALOG_069,1,6,30,200, "Sometimes you'll bump into\n\
invisible walls at the\n\
edges of the painting\n\
worlds. If you hit a wall\n\
while flying, you'll bounce\n\
back.")

DEFINE_DIALOG(DIALOG_070,1,5,30,200, "You can return to the\n\
castle's main hall at any\n\
time from the painting\n\
worlds where the enemies\n\
live.\n\
Just stop, stand still,\n\
press Start to pause the\n\
game, then select\n\
『Exit Course.』\n\
\n\
You don't have to collect\n\
all Power Stars in one\n\
course before going on to\n\
the next.\n\
\n\
Return later, when you're\n\
more experienced, to pick\n\
up difficult ones.\n\
\n\
\n\
Whenever you find a Star,\n\
a hint for finding the\n\
next one will appear on\n\
the course's start screen.\n\
\n\
You can, however, collect\n\
any of the remaining\n\
Stars next. You don't\n\
have to recover the one\n\
described by the hint.")

DEFINE_DIALOG(DIALOG_071,1,5,30,200, "Before you go down the\n\
slide, stop and turn\n\
around. You can climb\n\
the ruins even higher \n\
from there.")

DEFINE_DIALOG(DIALOG_072,1,5,30,200, "High winds ahead!\n\
Pull your Cap down tight.\n\
If it blows off, you'll\n\
have to find it on this\n\
mountain.")

DEFINE_DIALOG(DIALOG_073,1,4,95,200, "Aarrgh! Ahoy, matey. I\n\
have sunken treasure,\n\
here, I do.\n\
\n\
But to pluck the plunder,\n\
you must open the\n\
Treasure Chests in the\n\
right order.\n\
What order is that,\n\
ye say?\n\
\n\
\n\
I'll never tell!\n\
\n\
\t--The Cap'n")

DEFINE_DIALOG(DIALOG_074,1,5,30,200, "You can grab on to the\n\
edge of a cliff or ledge\n\
with your fingertips and\n\
hang down from it.\n\
\n\
To drop from the edge,\n\
either press the Control\n\
Stick in the direction of\n\
Mario's back or press the\n\
Ⓩ Button.\n\
To get up onto the ledge,\n\
either press Up on the\n\
Control Stick or press Ⓐ \n\
as soon as you grab the\n\
ledge to climb up quickly.")

DEFINE_DIALOG(DIALOG_075,1,5,30,200, "Mario!! My castle is in\n\
great peril. I know that\n\
Bowser is the cause...and\n\
I know that only you can\n\
stop him!\n\
The doors in the castle\n\
that have been sealed by\n\
Bowser can be opened only\n\
with Star Power.\n\
\n\
But there are secret\n\
paths in the castle,\n\
paths that Bowser hasn't\n\
found.\n\
\n\
One of those paths is in\n\
this room, and it holds\n\
one of the castle's Secret\n\
Stars!\n\
\n\
Find that Secret Star,\n\
Mario! It will help you\n\
on your quest. Please,\n\
Mario, you have to\n\
help us!\n\
Retrieve all of the\n\
Power Stars in the castle\n\
and free us from this\n\
awful prison!\n\
Please!")

DEFINE_DIALOG(DIALOG_076,1,4,30,200, "Drat! I thought for sure\n\
I could hide from you\n\
here! Oh - it's just you,\n\
Mario.\n\
Don't worry, I haven't\n\
been fooling around this\n\
whole time. Look what I\n\
found!")

DEFINE_DIALOG(DIALOG_077,1,2,150,200, "It is decreed that one\n\
shall pound the pillars.")

DEFINE_DIALOG(DIALOG_078,1,5,30,200, "Well well well...I thought\n\
somebody might figure\n\
out how to get up here.\n\
You know I originally\n\
intended for you to do so?\n\
Only, because of the \n\
slope design of the\n\
canyon walls (read: my\n\
noob modeling skills),\n\
this level would\n\
absolutely have to go\n\
without a death floor, \n\
otherwise you'd be \n\
falling out of the level\n\
left and right through\n\
those slopes.\n\
It was either sacrifice\n\
that or remake the walls\n\
...and god do I hate \n\
making walls.\n\
So anyway, congrats, \n\
you are either a l33t\n\
haX0r or you are simply\n\
very clever. No star for\n\
you - however, maybe\n\
you can be the first \n\
person to stand on top\n\
of Bowser's Pachinko\n\
Machine?")

DEFINE_DIALOG(DIALOG_079,1,4,30,200, "Owwwuu! Let me go!\n\
Uukee-kee! I was only\n\
teasing! Can't you take\n\
a joke?\n\
I'll tell you what, let's\n\
trade. If you let me go,\n\
I'll give you something\n\
really good.\n\
So, how about it?\n\
\n\
\tFree him/ Hold on")

DEFINE_DIALOG(DIALOG_080,1,1,30,200, "Eeeh hee hee hee!")

DEFINE_DIALOG(DIALOG_081,1,4,30,200, "The mystery is of Wet\n\
or Dry.\n\
And where does the\n\
solution lie?\n\
The city welcomes visitors\n\
with the depth they bring\n\
as they enter.")

DEFINE_DIALOG(DIALOG_082,1,4,30,200, "Wanna delete all\n\
your progress?\n\
\tYes\t\tNo")

DEFINE_DIALOG(DIALOG_083,1,6,30,200, "There's something strange\n\
about that clock. As you\n\
jump inside, watch the\n\
position of the big hand.\n\
Oh, look what I found!\n\
Here, Mario, catch!")

DEFINE_DIALOG(DIALOG_084,1,3,30,200, "Yeeoww! Unhand me,\n\
brute! I'm late, so late,\n\
I must make haste!\n\
This shiny thing? Mine!\n\
It's mine. Finders,\n\
keepers, losers...\n\
Late, late, late...\n\
Ouch! Take it then! A\n\
gift from Bowser, it was.\n\
Now let me be! I have a\n\
date! I cannot be late\n\
for tea!")

DEFINE_DIALOG(DIALOG_085,1,5,30,200, "You don't stand a ghost\n\
of a chance in this house.\n\
If you walk out of here,\n\
you deserve...\n\
...a Ghoul Medal...")

DEFINE_DIALOG(DIALOG_086,1,3,30,200, "Running around in circles\n\
makes some bad guys roll\n\
their eyes.")

DEFINE_DIALOG(DIALOG_087,1,4,30,200, "Santa Claus isn't the only\n\
one who can go down a\n\
chimney! Come on in!\n\
/--Cabin Proprietor")

DEFINE_DIALOG(DIALOG_088,1,5,30,200, "Work Elevator\n\
For those who get off\n\
here: Grab the pole to the\n\
left and slide carefully\n\
down.")

DEFINE_DIALOG(DIALOG_089,1,5,95,200, "Both ways fraught with\n\
danger! Watch your feet!\n\
Those who can't do the\n\
Long Jump, tsk, tsk. Make\n\
your way to the right.\n\
Right: Work Elevator\n\
\t/ Cloudy Maze\n\
Left: Black Hole\n\
\t/Underground Lake\n\
\n\
Red Circle: Elevator 2\n\
\t\t Underground Lake\n\
Arrow: You are here")

DEFINE_DIALOG(DIALOG_090,1,6,30,200, "Bwa ha ha ha!\n\
You've stepped right into\n\
my trap, just as I knew\n\
you would! I warn you,\n\
『Friend,』 watch your\n\
step!")

DEFINE_DIALOG(DIALOG_091,2,2,30,200, "Danger!\n\
Strong Gusts!\n\
But the wind makes a\n\
comfy ride.")

DEFINE_DIALOG(DIALOG_092,1,5,30,200, "Pestering me again, are\n\
you, Mario? Can't you see\n\
that I'm having a merry\n\
little time, making\n\
mischief with my minions?\n\
Now, return those Stars!\n\
My troops in the walls\n\
need them! Bwa ha ha!")

DEFINE_DIALOG(DIALOG_093,1,5,30,200, "So...you managed to\n\
reach me here after all.\n\
I'd be a liar to say I'm\n\
not impressed.\n\
But no matter...\n\
I'll crush you here and \n\
now. My minions will\n\
take care of you.")

DEFINE_DIALOG(DIALOG_094,1,4,30,200, "Get a good run up the\n\
slope! Do you remember\n\
the Long Jump? Run, press\n\
Ⓩ, then jump!")

DEFINE_DIALOG(DIALOG_095,1,4,30,200, "To read a sign, stand in\n\
front of it and press Ⓑ,\n\
like you did just now.\n\
\n\
When you want to talk to\n\
a Koopa Troopa or other\n\
animal, stand right in\n\
front of it.\n\
Please recover the Stars\n\
that were stolen by\n\
Bowser in this course.")

DEFINE_DIALOG(DIALOG_096,1,4,30,200, "The path is narrow here.\n\
Easy does it! No one is\n\
allowed on top of the\n\
mountain!\n\
And if you know what's\n\
good for you, you won't\n\
wake anyone who's\n\
sleeping!\n\
Move slowly,\n\
tread lightly.")

DEFINE_DIALOG(DIALOG_097,1,5,30,200, "Don't be a pushover!\n\
If anyone tries to shove\n\
you around, push back!\n\
It's one-on-one, with a\n\
fiery finish for the loser!")

DEFINE_DIALOG(DIALOG_098,1,2,95,200, "Come on in here...\n\
...heh, heh, heh...")

DEFINE_DIALOG(DIALOG_099,1,5,95,200, "Eh he he...\n\
You're mine, now, hee hee!\n\
I'll pass right through\n\
this wall. Can you do\n\
that? Heh, heh, heh!")

DEFINE_DIALOG(DIALOG_100,1,3,95,200, "Ukkiki...Wakkiki...kee kee!\n\
Ha! I snagged it!\n\
It's mine! Heeheeheeee!")

DEFINE_DIALOG(DIALOG_101,1,3,95,200, "Ackk! Let...go...\n\
You're...choking...me...\n\
Cough...I've been framed!\n\
This Cap? Oh, all right,\n\
take it. It's a cool Cap,\n\
but I'll give it back.\n\
I think it looks better on\n\
me than it does on you,\n\
though! Eeeee! Kee keee!")

DEFINE_DIALOG(DIALOG_102,1,5,30,200, "Pssst! The Boos are super\n\
shy. If you look them\n\
in the eyes, they fade\n\
away, but if you turn\n\
your back, they reappear.\n\
It's no use trying to hit\n\
them when they're fading\n\
away. Instead, sneak up\n\
behind them and punch.")

DEFINE_DIALOG(DIALOG_103,1,4,95,200, "Upon four towers\n\
one must alight...\n\
Then at the peak\n\
shall shine the light...")

DEFINE_DIALOG(DIALOG_104,1,5,30,200, "The shadowy star in front\n\
of you is a 『Star\n\
Marker.』 When you collect\n\
all 8 Red Coins, the Star\n\
will appear here.")

DEFINE_DIALOG(DIALOG_105,1,3,95,200, "Ready for blastoff! Come\n\
on, hop into the cannon!\n\
\n\
You can reach the Star on\n\
the floating island by\n\
using the four cannons.\n\
Use the Control Stick to\n\
aim, then press Ⓐ  to fire.\n\
\n\
If you're handy, you can\n\
grab on to trees or poles\n\
to land.")

DEFINE_DIALOG(DIALOG_106,1,2,95,200, "Ready for blastoff! Come\n\
on, hop into the cannon!")

DEFINE_DIALOG(DIALOG_107,1,3,95,200, "Ghosts...\n\
...don't...\n\
...DIE!\n\
Heh, heh, heh!\n\
Can you get out of here...\n\
...alive?")

DEFINE_DIALOG(DIALOG_108,1,2,95,200, "Boooooo-m! Here comes\n\
the master of mischief,\n\
the tower of terror,\n\
the Big Boo!\n\
Ka ha ha ha...")

DEFINE_DIALOG(DIALOG_109,1,4,95,200, "Ooooo Nooooo!\n\
Talk about out-of-body\n\
experiences--my body\n\
has melted away!\n\
Have you run in to any\n\
headhunters lately??\n\
I could sure use a new\n\
body!\n\
Brrr! My face might\n\
freeze like this!")

DEFINE_DIALOG(DIALOG_110,1,5,95,200, "I need a good head on my\n\
shoulders. Do you know of\n\
anybody in need of a good\n\
body? Please! I'll follow\n\
you if you do!")

DEFINE_DIALOG(DIALOG_111,1,4,95,200, "Perfect! What a great\n\
new body! Here--this is a\n\
present for you. It's sure\n\
to warm you up.")

DEFINE_DIALOG(DIALOG_112,1,4,30,200, "Collect as many coins as\n\
possible! They'll refill\n\
your Power Meter.\n\
\n\
You can check to see how\n\
many coins you've\n\
collected in each of the\n\
15 enemy worlds.\n\
You can also recover\n\
power by touching the\n\
Spinning Heart.\n\
\n\
The faster you run\n\
through the heart, the\n\
more power you'll recover.")

DEFINE_DIALOG(DIALOG_113,1,6,30,200, "There are special Caps in\n\
the red, green and blue\n\
blocks. Step on the\n\
switches in the hidden\n\
courses to activate the\n\
Cap Blocks.")

DEFINE_DIALOG(DIALOG_114,1,5,95,200, "It makes me so mad! We\n\
build your houses, your\n\
castles. We pave your\n\
roads, and still you\n\
walk all over us.\n\
Do you ever say thank\n\
you? No! Well, you're not\n\
going to wipe your feet\n\
on me! I think I'll crush\n\
you just for fun!\n\
Do you have a problem\n\
with that? Just try to\n\
pound me, wimp! Ha!")

DEFINE_DIALOG(DIALOG_115,1,5,95,200, "No! Crushed again!\n\
I'm just a stepping stone,\n\
after all. I won't gravel,\n\
er, grovel. Here, you win.\n\
Take this with you!")

DEFINE_DIALOG(DIALOG_116,1,5,95,200, "Whaaa....Whaaat?\n\
Can it be that a\n\
pipsqueak like you has\n\
defused the Bob-omb\n\
king????\n\
You might be fast enough\n\
to ground me, but you'll\n\
have to pick up the pace\n\
if you want to take King\n\
Bowser by the tail.\n\
Methinks my troops could\n\
learn a lesson from you!\n\
Here is your Star, as I\n\
promised, Mario.\n\
\n\
If you want to see me\n\
again, select this Star\n\
from the menu. For now,\n\
farewell.")

DEFINE_DIALOG(DIALOG_117,1,5,95,200, "So...you think you can\n\
just enter an ancient\n\
chamber without\n\
consequence? Just waltz\n\
right in?\n\
We don't take kindly to\n\
intruders. If you're\n\
looking for hospitality,\n\
we'd be happy to hand\n\
you defeat.")

DEFINE_DIALOG(DIALOG_118,1,5,95,200, "This is getting out of\n\
hand. We thought we\n\
could count on your\n\
demise but it slipped\n\
right through our fingers.\n\
You may have this star,\n\
but in return you will\n\
leave us, so that we may\n\
rest...")

DEFINE_DIALOG(DIALOG_119,1,6,30,200, "Grrr! I was a bit\n\
careless. This is not as I\n\
had planned...but I still\n\
hold the power of the\n\
Stars, and I still have\n\
Peach.\n\
Bwa ha ha! You'll get no\n\
more Stars from me! I'm\n\
not finished with you yet,\n\
but I'll let you go for\n\
now. You'll pay for this...\n\
later!")

DEFINE_DIALOG(DIALOG_120,1,4,30,200, "Ooowaah! Can it be that\n\
I've lost??? The power of\n\
the Stars has failed me...\n\
this time.\n\
Consider this a draw.\n\
Next time, I'll be in\n\
perfect condition.\n\
\n\
Now, if you want to see\n\
your precious Princess,\n\
come to the top of the\n\
tower.\n\
I'll be waiting!\n\
Gwa ha ha ha!")

DEFINE_DIALOG(DIALOG_121,1,5,30,200, "Bwaa ha ha...defeated \n\
again...I really wanted to\n\
keep this crown. But I\n\
guess you can have it\n\
back.\n\
By the way, if you have\n\
all 30 stars, then reset\n\
after the cake screen \n\
and go stand on top of \n\
the sign in the castle \n\
lobby. Just do it.\n\
Bahhhhh...any \n\
more words are \n\
meaningless at this \n\
point....\n\
\n\
So long, gay Mario!")

DEFINE_DIALOG(DIALOG_122,1,4,30,200, "The Black Hole\n\
Right: Work Elevator\n\
\t/ Cloudy Maze\n\
Left: Underground Lake")

DEFINE_DIALOG(DIALOG_123,1,4,30,200, "Metal Cavern\n\
Right: To Waterfall\n\
Left: Metal Cap Switch")

DEFINE_DIALOG(DIALOG_124,1,4,30,200, "")

DEFINE_DIALOG(DIALOG_125,1,3,30,200, "Hazy Maze-Exit\n\
Danger! Closed.\n\
Turn back now.")

DEFINE_DIALOG(DIALOG_126,2,3,30,200, "Up: Black Hole\n\
Right: Work Elevator\n\
\t/ Hazy Maze")

DEFINE_DIALOG(DIALOG_127,3,4,30,200, "Underground Lake\n\
Right: Metal Cave\n\
Left: Abandoned Mine\n\
\t/(Closed)\n\
A gentle sea dragon lives\n\
here. Pound on his back to\n\
make him lower his head.\n\
Don't become his lunch.")

DEFINE_DIALOG(DIALOG_128,1,4,95,200, "You must fight with\n\
honor! It is against the\n\
royal rules to throw the\n\
king out of the ring!")

DEFINE_DIALOG(DIALOG_129,1,5,30,200, "Welcome to the Vanish\n\
Cap Switch Course! All of\n\
the blue blocks you find\n\
will become solid once you\n\
step on the Cap Switch.\n\
You'll disappear when you\n\
put on the Vanish Cap, so\n\
you'll be able to elude\n\
enemies and walk through\n\
many things. Try it out!")

DEFINE_DIALOG(DIALOG_130,1,5,30,200, "Welcome to the Metal Cap\n\
Switch Course! Once you\n\
step on the Cap Switch,\n\
the green blocks will\n\
become solid.\n\
When you turn your body\n\
into metal with the Metal\n\
Cap, you can walk\n\
underwater! Try it!")

DEFINE_DIALOG(DIALOG_131,1,5,30,200, "Welcome to the Wing Cap\n\
Course! Step on the red\n\
switch at the top of the\n\
tower, in the center of\n\
the rainbow ring.\n\
When you trigger the\n\
switch, all of the red\n\
blocks you find will\n\
become solid.\n\
\n\
Try out the Wing Cap! Do\n\
the Triple Jump to take\n\
off and press Ⓩ to land.\n\
\n\
\n\
Pull back on the Control\n\
Stick to go up and push\n\
forward to nose down,\n\
just as you would when\n\
flying an airplane.")

DEFINE_DIALOG(DIALOG_132,1,4,30,200, "Whoa, Mario, pal, you\n\
aren't trying to cheat,\n\
are you? Shortcuts aren't\n\
allowed.\n\
Now, I know that you\n\
know better. You're\n\
disqualified! Next time,\n\
play fair!")

DEFINE_DIALOG(DIALOG_133,1,6,30,200, "Huh? You want to get to\n\
the mountain's peak? I'm\n\
not sure that's possible\n\
anymore.\n\
\n\
\n\
Bowser attacked our\n\
mountain and destroyed\n\
the path to the top. We\n\
toads dug that cave into \n\
the mountain and began\n\
building a new path to\n\
the top, but we ran out\n\
of resources.\n\
\n\
\n\
\n\
\n\
We have a storage \n\
facility full of boxes in \n\
City Hall but Bowser \n\
sealed the door, now the\n\
mayor is stuck inside! \n\
\n\
Only the magic of\n\
a Power Star can unlock\n\
this door. We Toads \n\
can't jump across gaps \n\
with our puny legs - can\n\
we count on you, Mario?\n\
Since you can't get to the\n\
top, maybe you should\n\
try going as far up as\n\
you can. I think I can see\n\
a Power Star from here..")

DEFINE_DIALOG(DIALOG_134,1,5,30,200, "See that star on the\n\
mountain's peak? Get\n\
some distance from here,\n\
then take a look. I \n\
wonder if you can get to \n\
the top and grab it...")

DEFINE_DIALOG(DIALOG_135,1,5,30,200, "Mario! The mayor had\n\
his crew place ladders and \n\
materials so you \n\
can climb further \n\
up the mountain.\n\
\n\
You don't need to go \n\
through the cave this\n\
time either. Just climb\n\
the snow cliffs behind\n\
you and use the trail\n\
we made with some\n\
materials. It's a shortcut!\n\
\n\
\n\
\n\
The town elder lives \n\
somewhere up there - \n\
you should speak to him \n\
and see if he has any \n\
ideas about how to get \n\
the star on the \n\
mountain's peak.")

DEFINE_DIALOG(DIALOG_136,1,6,30,200, "I'm the mayor. I want to\n\
thank you personally for\n\
getting us opened back\n\
up. We have a star hidden\n\
in the fake crate in our\n\
box storage one room\n\
down from here. You are\n\
welcome to it.\n\
\n\
\n\
\n\
\n\
Oh, you need help getting\n\
further up the mountain?\n\
We are a bit low on\n\
resources, but if you can\n\
provide the funds, we can\n\
certainly accomodate you.\n\
The only currency we\n\
accept here in Toad\n\
Taiga is Red Coins! Go\n\
collect them on the next\n\
star and I'll be happy to\n\
set up ladders for you.")

DEFINE_DIALOG(DIALOG_137,1,6,30,200, "Thanks, Mario! The castle\n\
is recovering its energy\n\
as you retrieve Power\n\
Stars, and you've chased\n\
Bowser right out of here,\n\
on to some area ahead.\n\
Oh, by the by, are you\n\
collecting coins? Special\n\
Stars appear when you\n\
collect 100 coins in each\n\
of the 15 courses!")

DEFINE_DIALOG(DIALOG_138,1,5,30,200, "Welcome to the earliest\n\
version of Bountiful\n\
Basin! It's not the first\n\
level I've ever done, but\n\
it was the first to be\n\
completed.\n\
\n\
\n\
\n\
\n\
As you can see,\n\
the level maintained its\n\
basic shape from beta to\n\
final version. The biggest\n\
change was definitely\n\
the decision to expand\n\
the level and introduce\n\
the Beach Bowl \n\
Galaxy-esque water\n\
basin shape (hence the\n\
name). The upper area\n\
was also expanded and\n\
that hideous large tree\n\
to the left was\n\
discarded.\n\
There was a cave behind\n\
the waterfall at this\n\
point but no Area 2 yet.\n\
\n\
\n\
The one thing that never\n\
changed, however, was \n\
the cutout for the river. \n\
It's been the same this \n\
whole time!\n\
Anyway, if you read this\n\
far, there is a surprise\n\
for those of you who\n\
can get on top of the \n\
waterfall.")

DEFINE_DIALOG(DIALOG_139,1,5,30,200, "Oww, my eyes! Yeah,\n\
this level never got real\n\
far before I nuked most\n\
of it and kept only a few\n\
parts to work with.\n\
As you go around the\n\
bend, you might notice\n\
it's the same starting\n\
path as the finished\n\
level.\n\
No secrets here, by the\n\
way, that was a one\n\
time thing!")

DEFINE_DIALOG(DIALOG_140,1,5,30,200, "And here's Brimstone\n\
Banks in its beta glory.\n\
This one is probably\n\
closest to the completed\n\
version of all the levels.\n\
Some major cosmetic\n\
differences...you might\n\
have noticed you are\n\
walled in and unable to\n\
see beyond the spawn\n\
point. Another big\n\
difference is this beta\n\
version is scaled larger\n\
than the finished level.\n\
Jump around a bit and\n\
you'll feel how much\n\
more annoying it is to\n\
have a big empty level\n\
like this. When you have\n\
a decent level but it's\n\
just so big and empty,\n\
scale it down!\n\
\n\
\n\
\n\
By the way, I've\n\
deactivated the lava, so\n\
feel free to explore to\n\
your heart's content.")

DEFINE_DIALOG(DIALOG_141,1,3,150,200, "Thank you so much\n\
for playing the hack!\n\
Hope you enjoyed it!\n\
Made by Stunning Cactus\n\
Nobbie and aglab2")

DEFINE_DIALOG(DIALOG_142,1,5,150,200, "You've recovered three\n\
Power Stars! Now you can\n\
open any door with a 3\n\
on its star.\n\
\n\
You can come and go from\n\
the open courses as you\n\
please. The enemies ahead\n\
are even meaner, so be\n\
careful!")

DEFINE_DIALOG(DIALOG_143,1,6,150,200, "You've recovered eight of\n\
the Power Stars! Now you\n\
can open the door with\n\
the big Star! But Bowser\n\
is just ahead...can you\n\
hear the Princess calling?")

DEFINE_DIALOG(DIALOG_144,1,6,150,200, "You've recovered 30\n\
Power Stars! Now you can\n\
open the door with the\n\
big Star! But before you\n\
move on, how's it going\n\
otherwise?\n\
Did you pound the two\n\
columns down? You didn't\n\
lose your hat, did you?\n\
If you did, you'll have to\n\
stomp on the condor to\n\
get it back!\n\
They say that Bowser has\n\
sneaked out of the sea\n\
and into the underground.\n\
Have you finally\n\
cornered him?")

DEFINE_DIALOG(DIALOG_145,1,6,150,200, "You've recovered 50\n\
Power Stars! Now you can\n\
open the Star Door on the\n\
third floor. Bowser's\n\
there, you know.\n\
\n\
Oh! You've found all of\n\
the Cap Switches, haven't\n\
you? Red, green and blue?\n\
The Caps you get from the\n\
colored blocks are really\n\
helpful.\n\
Hurry along, now. The\n\
third floor is just ahead.")

DEFINE_DIALOG(DIALOG_146,1,6,150,200, "You've found 70 Power\n\
Stars! The mystery of the\n\
endless stairs is solved,\n\
thanks to you--and is\n\
Bowser ever upset! Now,\n\
on to the final bout!")

DEFINE_DIALOG(DIALOG_147,1,5,30,200, "Are you using the Cap\n\
Blocks? You really should,\n\
you know.\n\
\n\
\n\
To make them solid so you\n\
can break them, you have\n\
to press the colored Cap\n\
Switches in the castle's\n\
hidden courses.\n\
You'll find the hidden\n\
courses only after\n\
regaining some of the\n\
Power Stars.\n\
\n\
The Cap Blocks are a big\n\
help! Red for the Wing\n\
Cap, green for the Metal\n\
Cap, blue for the Vanish\n\
Cap.")

DEFINE_DIALOG(DIALOG_148,1,5,30,200, "And welcome to beta\n\
Desiccated Desert. It \n\
looks like a big piece of\n\
shit, and that's because \n\
it is the first level I ever \n\
tried to make. It was \n\
also the last of the 4 to \n\
be completed.\n\
\n\
\n\
Originally it was called\n\
Desert Ruins, and I\n\
wanted it to be the hub.\n\
But things change.\n\
\n\
If you look at the broken\n\
castle structures (the tan\n\
brick objects), you might\n\
recognize I kept those\n\
and used them in Area\n\
2 of the finished\n\
Desiccated Desert. I\n\
wanted to pay tribute to\n\
this old level since it was\n\
my starting point.\n\
Anyway, take a quick\n\
look around, though\n\
there's not much to see,\n\
and thank you so much\n\
for playing my game!\n\
This is all I have left to\n\
show you, unless you are\n\
one of those freaks that\n\
visited these levels out \n\
of order.")

DEFINE_DIALOG(DIALOG_149,1,5,30,200, "Congratulations on\n\
completing the game! I\n\
always liked games that\n\
had bonus content after\n\
you beat the main game.\n\
For those who are\n\
interested, I've dug up\n\
the earliest version I\n\
could find of each of the \n\
4 Worlds in the game.\n\
They are available for\n\
your perusal. There are\n\
no stars in these levels, \n\
as I didn't want to risk\n\
requiring speedrunners \n\
to travel to \n\
broken, unfinished levels.\n\
\n\
\n\
\n\
Each level has a signpost\n\
that details a bit about\n\
the major changes that\n\
took place between the\n\
beta level and the\n\
finished level, and a \n\
warp pipe for you to\n\
return here.\n\
\n\
\n\
It's possible you will\n\
encounter situations\n\
where you get stuck or\n\
softlock since these levels\n\
were left as is - in such\n\
a case you can just pause\n\
warp out.\n\
\n\
\n\
\n\
I hope you enjoy checking\n\
out the early stages of\n\
the modeling process of\n\
this game :)")

DEFINE_DIALOG(DIALOG_150,1,5,30,200, "")

DEFINE_DIALOG(DIALOG_151,1,4,30,200, "I can't take this\n\
anymore! First you get\n\
me all wet, then you\n\
stomp on me!\n\
Now I'm really, really,\n\
REALLY mad!\n\
Waaaaaaaaaaaaaaaaa!!!")

DEFINE_DIALOG(DIALOG_152,1,3,30,200, "")

DEFINE_DIALOG(DIALOG_153,1,4,30,200, "")

DEFINE_DIALOG(DIALOG_154,1,6,30,200, "By the way, you\n\
wouldn't happen to have\n\
seen my pal around,\n\
would you? We were in\n\
the middle of a game. I\n\
wonder where he went?")

DEFINE_DIALOG(DIALOG_155,1,4,30,200, "Say, you haven't seen\n\
my buddy around here,\n\
have you? We two were\n\
playing hide-n-seek.")

DEFINE_DIALOG(DIALOG_156,1,5,30,200, "The world inside the\n\
clock is so strange!\n\
When you jump inside,\n\
watch the position of\n\
the big hand!")

DEFINE_DIALOG(DIALOG_157,1,5,30,200, "After about a month of\n\
working on it, it turned\n\
into this. I was still\n\
learning how to use\n\
Sketchup so the process\n\
was a bit slow, but it's\n\
pretty cool to see the\n\
transformation.\n\
\n\
\n\
This level was originally\n\
called 『Midnight\n\
Meadows』, but the name\n\
was scrapped after I\n\
expanded the water.\n\
I made it possible to\n\
fall off of the level so you\n\
can get to some of the\n\
areas on the outside of\n\
it.\n\
After you're done\n\
checking it out, jump\n\
back through this pipe\n\
to exit, then return to\n\
the pipe at the spawn of\n\
the first beta version.")

DEFINE_DIALOG(DIALOG_158,1,6,30,200, "")

DEFINE_DIALOG(DIALOG_159,1,6,30,200, "")

DEFINE_DIALOG(DIALOG_160,1,4,30,200, "")

DEFINE_DIALOG(DIALOG_161,1,4,30,200, "Mario!!!\n\
It that really you???\n\
It has been so long since\n\
our last adventure!\n\
They told me that I might\n\
see you if I waited here,\n\
but I'd just about given\n\
up hope!\n\
Is it true? Have you\n\
really beaten Bowser? And\n\
restored the Stars to the\n\
castle?\n\
And saved the Princess?\n\
I knew you could do it!\n\
Now I have a very special\n\
message for you.\n\
『Thanks for playing Super\n\
Mario 64! This is the\n\
end of the game, but not\n\
the end of the fun.\n\
We want you to keep on\n\
playing, so we have a\n\
little something for you.\n\
We hope that you like it!\n\
Enjoy!!!』\n\
\n\
The Super Mario 64 Team")

DEFINE_DIALOG(DIALOG_162,1,4,30,200, "No, no, no! Not you\n\
again! I'm in a great\n\
hurry, can't you see?\n\
\n\
I've no time to squabble\n\
over Stars. Here, have it.\n\
I never meant to hide it\n\
from you...\n\
It's just that I'm in such\n\
a rush. That's it, that's\n\
all. Now, I must be off.\n\
Owww! Let me go!")

DEFINE_DIALOG(DIALOG_163,1,5,30,200, "Noooo! You've really\n\
beaten me this time,\n\
Mario! I can't stand\n\
losing to you!\n\
\n\
My troops...worthless!\n\
They've turned over all\n\
the Power Stars! What?!\n\
There are 120 in all???\n\
\n\
Amazing! There were some\n\
in the castle that I\n\
missed??!!\n\
\n\
\n\
Now I see peace\n\
returning to the world...\n\
Oooo! I really hate that!\n\
I can't watch--\n\
I'm outta here!\n\
Just you wait until next\n\
time. Until then, keep\n\
that Control Stick\n\
smokin'!\n\
Buwaa ha ha!")

DEFINE_DIALOG(DIALOG_164,1,4,30,200, "Mario! What's up, pal?\n\
I haven't been on the\n\
slide lately, so I'm out\n\
of shape.\n\
Still, I'm always up for a\n\
good race, especially\n\
against an old sleddin'\n\
buddy.\n\
Whaddya say?\n\
Ready...set...\n\
\n\
\tGo\t\t Don't Go")

DEFINE_DIALOG(DIALOG_165,1,5,30,200, "I take no responsibility\n\
whatsoever for those who\n\
get dizzy and pass out\n\
from running around\n\
this post.")

DEFINE_DIALOG(DIALOG_166,1,4,30,200, "I'll be back soon.\n\
I'm out training now,\n\
so come back later.\n\
\t--Koopa the Quick")

DEFINE_DIALOG(DIALOG_167,1,4,30,200, "Princess Toadstool's\n\
castle is just ahead.\n\
\n\
\n\
Press Ⓐ  to jump, Ⓩ to\n\
crouch, and Ⓑ to punch,\n\
read a sign, or grab\n\
something.\n\
Press Ⓑ again to throw\n\
something you're holding.")

DEFINE_DIALOG(DIALOG_168,1,5,30,200, "Hey! Knock it off! That's\n\
the second time you've\n\
nailed me. Now you're\n\
asking for it, linguine\n\
breath!")

DEFINE_DIALOG(DIALOG_169,1,4,30,200, "Keep out!\n\
That means you!\n\
Arrgghh!\n\
\n\
Anyone entering this cave\n\
without permission will\n\
meet certain disaster.")

DEFINE_DIALOG(DIALOG_CONFIRM_DELETE, NO_SOUND, 4, 30, 200, "\
Are you sure you want to\n"
"delete all save files?\n\n"
"Yes   No")
