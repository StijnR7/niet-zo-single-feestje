/*
 * Niet-zo-single-feestje - hart-ketting prototype
 *
 * Een RGB-led toont de relatiestatus van de drager.
 * Een knop wisselt tussen de statussen (dummydata, geen netwerk).
 *
 * Aansluitingen (common cathode RGB-led, elk met 220 ohm weerstand):
 *   rood  -> pin 9
 *   groen -> pin 10
 *   blauw -> pin 11
 *   knop  -> pin 2 en GND (interne pull-up)
 */

const int PIN_ROOD = 9;
const int PIN_GROEN = 10;
const int PIN_BLAUW = 11;
const int PIN_KNOP = 2;

enum Status { SINGLE, BEZET, INGEWIKKELD, AANTAL_STATUSSEN };

struct Kleur {
  byte rood;
  byte groen;
  byte blauw;
};

const Kleur STATUS_KLEUREN[AANTAL_STATUSSEN] = {
  {0, 255, 0},    // single: groen
  {255, 0, 0},    // bezet: rood
  {255, 180, 0},  // het is ingewikkeld: geel
};

const char *STATUS_NAMEN[AANTAL_STATUSSEN] = {"single", "bezet", "het is ingewikkeld"};

const unsigned long DEBOUNCE_MS = 50;

Status huidigeStatus = SINGLE;
int vorigeKnopStand = HIGH;
unsigned long laatsteWissel = 0;

void toonKleur(const Kleur &kleur) {
  analogWrite(PIN_ROOD, kleur.rood);
  analogWrite(PIN_GROEN, kleur.groen);
  analogWrite(PIN_BLAUW, kleur.blauw);
}

void toonStatus() {
  toonKleur(STATUS_KLEUREN[huidigeStatus]);
  Serial.print("Status: ");
  Serial.println(STATUS_NAMEN[huidigeStatus]);
}

void setup() {
  pinMode(PIN_ROOD, OUTPUT);
  pinMode(PIN_GROEN, OUTPUT);
  pinMode(PIN_BLAUW, OUTPUT);
  pinMode(PIN_KNOP, INPUT_PULLUP);
  Serial.begin(9600);
  toonStatus();
}

void loop() {
  int knopStand = digitalRead(PIN_KNOP);
  unsigned long nu = millis();

  if (knopStand == LOW && vorigeKnopStand == HIGH && nu - laatsteWissel > DEBOUNCE_MS) {
    huidigeStatus = static_cast<Status>((huidigeStatus + 1) % AANTAL_STATUSSEN);
    laatsteWissel = nu;
    toonStatus();
  }

  vorigeKnopStand = knopStand;
}
