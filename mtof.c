/* listing 1.2. Calculate frequency of a MIDI Note number */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc != 2) { printf("usage: ./ftom <MIDInote>\n"); return 1; }
  int mn = atoi (argv[1]);

  double semitone_ratio;
  double c0; /* for frequency of MIDI Note 0 */
  double c5; /* for frequency of Middle C */
  double frequency; /* ... which we want to find */
  int midinote; /* given this note */
  float cm;

  /* calculate trequired numbers */

  semitone_ratio = pow(2, 1.0/12.0); /* approx 1.0594631 */
  /* find middle C, three semitones above low A = 220 */
  c5 = 220.0 * pow(semitone_ratio, 3);

  /* MIDI Note 0 is C, 5 octaves below Middle C */
  c0 = c5 * pow(0.5, 5);

  if(mn >= 0 && mn <= 127) midinote = mn;
  else { printf("first argument must be midinote between 0 - 127\n"); return 1; }
  frequency = c0 * pow(semitone_ratio, midinote);

  printf("MIDI Note %d has frequency %f\n", midinote,frequency);
  return 0;
}
