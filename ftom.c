/* listing 1.2. Calculate MIDI Note number from frequency

We define pitchbend as a percentage deviation half a semitone above or below a MIDI note.
Maximum deviation is therefore +-50 percent.
For example, given a frequency of 430 Hz, the nearest notes are 69 (f = 440) and 68 (f = 415.3).

The deviation is therefore: 10/24.7 = -0.398 = -40 percent (approximately).

Extend freq2midi to report the frequency deviation above or below the calculated MIDI note, as a percentage.

(Hint: To print a per- centage symbol using printf, precede it with the same symbol.)
         int bend = 45;
         printf("pitchbend = %d%%\n",bend);
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

  double freqArg = atof (argv[1]);
  double fracmidi;
  double semitone_ratio;
  double c0; /* for frequency of MIDI Note 0 */
  double c5; /* for frequency of Middle C */
  double frequency; /* ... which we want to find */
  int midinote; /* given this note */
  int midilow;
  double pitchbend;
  double integral;

  semitone_ratio = pow(2, 1/12.0); /* approx 1.0594631 */
  /* find middle C, three semitones above low A = 220 */
  c5 = 220.0 * pow(semitone_ratio, 3);
  /* MIDI Note 0 is C, 5 octaves below Middle C */
  c0 = c5 * pow(0.5, 5);

  /* find nearest MIDI note to a given frequency in Hz */
  /* uses the log rule:
   log_a(N) = log_b(N) / log_b(a)
       to find the log of a value to base 'semitone_ratio'.
  */
  frequency = freqArg;
  fracmidi = log(frequency / c0) / log(semitone_ratio);
  /* round fracmidi up to the nearest whole number
  midinote = (int) (fracmidi + 0.5);
   */

  pitchbend = modf(fracmidi, &integral) * 100;
  midinote = integral;
  
  printf("The nearest MIDI note to the frequency %f is %d\n", frequency, midinote);
  printf("pitchbend = %f%%\n", pitchbend);
  printf("Raw fracmidi = %f\n", fracmidi);
  return 0;
}
