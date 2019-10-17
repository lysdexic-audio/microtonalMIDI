/* listing 1.2. Calculate frequency of a MIDI Note number

Exercise 1.2.5
(a) The sounding length of a string sounding C4 (‘‘middle C’’) is given as 660 cm.
Modify listing 1.2 to print out the lengths of string required for each semitone up to the next octave (C5, 330 cm).
(b) What further language facilities would make this task easier?

*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

  int mn = atoi (argv[1]);
  double semitone_ratio;
  double c0; /* for frequency of MIDI Note 0 :: really this is C-1 */
  double c5; /* for frequency of Middle C :: really this is C4 */
  double frequency; /* ... which we want to find */
  int midinote; /* given this note */
  double cm;
  double c5cm;
  double c0cm;

  if(mn >= 0 && mn <= 127) midinote = mn;
  else { printf("first argument must be midinote between 0 - 127\n"); return 1; }

  /* calculate required numbers */
  semitone_ratio = pow(2, 1/12.0); /* approx 1.0594631 */
  /* find middle C, three semitones above low A = 220 */
  c5 = 220.0 * pow(semitone_ratio, 3);
  c5cm = 660.0;

  /* MIDI Note 0 is C, 5 octaves below Middle C */
  c0 = c5 * pow(0.5, 5);
  c0cm = c5cm * pow(2, 5);
  /* calculate a frequency for a given MIDI Note Number */
  frequency = c0 * pow(semitone_ratio, midinote);
  cm = c0cm / pow(semitone_ratio, midinote);
  printf("MIDI Note %d has frequency %f\n", midinote,frequency);
  printf("MIDI Note %d has string length of %f cm\n", midinote,cm);
  return 0;
}
