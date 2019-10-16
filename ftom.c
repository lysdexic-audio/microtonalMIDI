/* listing 1.2. Calculate MIDI Note number from frequency */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

  double freqArg = atof (argv[1]);

  double semitone_ratio;
  double c0; /* for frequency of MIDI Note 0 */
  double c5; /* for frequency of Middle C */
  double frequency; /* ... which we want to find */
  int midinote; /* given this note */

  /* find nearest MIDI note to a given frequency in Hz */
  /* uses the log rule:
   log_a(N) = log_b(N) / log_b(a)
       to find the log of a value to base 'semitone_ratio'.
  */
  frequency = freqArg;
  fracmidi = log(frequency / c0) / log(semitone_ratio);
  /* round fracmidi to the nearest whole number */
  midinote = (int) (fracmidi + 0.5);
  printf("The nearest MIDI note to the frequency %f is %d\n," frequency, midinote);
  
  return 0;
}
