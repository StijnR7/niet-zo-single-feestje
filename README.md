# Niet-zo-single-feestje 💗

Arduino-prototype voor een interactieve **hart-ketting/broche**, gemaakt voor Hackathon 6.

## De opdracht

Poppodium **013 (Tilburg)** organiseert rond Valentijnsdag het feest *Smerrig*, waar je je geliefde meeneemt of een nieuwe liefde ontmoet. Eerder gebruikte 013 gekleurde bekers (single / bezet / "het is ingewikkeld") en een briefjessysteem met nummers. Nu willen ze iets nieuws:

> Bezoekers krijgen een hart-ketting of broche met daarin een microcontroller (Arduino). Bedenk creatief hoe die gebruikt wordt: lichtjes, connecties, geluid, enzovoort.

Het prototype wordt gebouwd in [Tinkercad](https://www.tinkercad.com/). Er wordt rekening gehouden met de doelgroep, de stakeholders, de techniek en de productie.

## Concept

Ik werk dit nog uit. Het startpunt in [`src/hart_ketting/hart_ketting.ino`](src/hart_ketting/hart_ketting.ino):

- Een **RGB-led** laat je relatiestatus zien: 🟢 single, 🔴 bezet, 🟡 het is ingewikkeld.
- Met een **knop** wissel je van status.
- De code gebruikt dummydata. Een verbinding tussen kettingen (bijvoorbeeld IR of NFC) volgt in een latere versie.

## Projectfases

| Fase | Werkproces | Op te leveren | Map |
|------|-----------|----------------|-----|
| 1. Ontwerpen | B1-K1-W2 | Datamodel/classdiagram, mockups/wireframes, flowcharts, privacy & ethiek, akkoord leidinggevende | [`docs/1-ontwerp`](docs/1-ontwerp) |
| 2. Realiseren | B1-K1-W3 | Git-repo met het prototype, code met dummydata, systeem- en gebruikersdocumentatie | [`src`](src), [`docs/2-realisatie`](docs/2-realisatie) |
| 3. Testen en verbeteren | B1-K1-W4 | Integratietest, acceptatietest, testrapport, uitlegvideo | [`docs/3-testen`](docs/3-testen) |

**Werkwijze:** individueel, Scrum/agile, 3 weken. Per sprint is er een product review en een retrospective.

## Mappenstructuur

```
├── src/hart_ketting/      Arduino-code (open met de Arduino IDE of plak in Tinkercad)
└── docs/
    ├── 1-ontwerp/         ontwerpdocumenten
    ├── 2-realisatie/      systeem- en gebruikersdocumentatie
    └── 3-testen/          testplannen en testrapporten
```

## Aan de slag

1. Open `src/hart_ketting/hart_ketting.ino` in de Arduino IDE of in een Tinkercad Circuits-project.
2. Sluit het circuit aan volgens de pinnen bovenaan het bestand.
3. Upload de code of start de simulatie. Druk op de knop om van status te wisselen.
