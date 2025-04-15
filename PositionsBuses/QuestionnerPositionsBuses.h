/*******************************************************************************
QuestionnerPositionsBuses.H
********************************************************************************/

#ifndef QUESTIONNERPOSITIONSBUSES_H
#define QUESTIONNERPOSITIONSBUSES_H

// Définition des constantes
#define HALL_SENSOR_PIN 25 // Pin pour le capteur Hall
#define SEUIL_BAS 0        // Seuil pour pas d'aimant
#define SEUIL_HAUT 50      // Seuil pour aimant détecté

// Déclarations des registres ADC 
#define ADC0_SC1A       (*((volatile unsigned int *)0x4003B000)) // Adresse fictive pour ADC0_SC1A
#define ADC0_RA         (*((volatile unsigned int *)0x4003B004)) // Adresse fictive pour ADC0_RA
#define ADC_SC1_ADCH(x) ((x) & 0x1F) // Masque pour le canal ADC
#define ADC_SC1_COCO_MASK 0x80 // Masque pour COCO (Conversion Complete Flag)


void initADC(void);
unsigned int readADC(void);
int QuestionnerPositionAimantsBuses(void);
void PositionsBuses(void); 

#endif