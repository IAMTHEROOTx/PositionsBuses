/*********************************************************************************
QuestionnerPositionsBuses.C 
********************************************************************************/

#include <stdio.h>

#include "QuestionnerPositionsBuses.h" 


void initADC(void) {
    ADC0_SC1A = ADC_SC1_ADCH(HALL_SENSOR_PIN); 
}

// Fonction pour lire la valeur du capteur Hall
unsigned int readADC(void) {
    // Démarrez la conversion ADC
    ADC0_SC1A = ADC_SC1_ADCH(HALL_SENSOR_PIN);  // Configurer l'ADC pour lire le capteur Hall

    while ((ADC0_SC1A & ADC_SC1_COCO_MASK) == 0);  

    return ADC0_RA;
}

// Fonction pour interroger la position des aimants
int QuestionnerPositionAimantsBuses(void) {
    unsigned int valeurCapteur = readADC();  // Lire la valeur convertie

    if (valeurCapteur < SEUIL_BAS) {
        return 0;  // Pas d'aimant
    } else if (valeurCapteur > SEUIL_HAUT) {
        return 1;  // Aimant détecté
    } else {
        return 0;  
    }
}

// Fonction principale pour interroger les positions des bus
void PositionsBuses(void) {
    initADC();

    while (1) {
        int result = QuestionnerPositionAimantsBuses(); // Lire la position des aimants

        if (result == 0) {
            printf("Pas d'aimant détecté\n");
        } else if (result == 1) {
            printf("Aimant détecté\n");
        }
    }
}