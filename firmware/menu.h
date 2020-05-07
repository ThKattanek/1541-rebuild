#ifndef MENUE_H
#define MENUE_H

///
/// \brief Mögliche Typen die ein Parameter annehmen kann
///
enum TYP {
    /// \brief Angabe in Prozet von 0% - 100%
    PERCENT,
    /// \brief Eine Liste von Strings.
    LIST,
    /// \brief Vorzeichenbehaftete Ganzahl
    INT,
    /// \brief Vorzeichenlose Ganzzahl
    UINT,
    /// \brief Boolean (TRUE oder FALSE)
    BOOL,
    /// \brief Angabe in Grad von 0.0° - 360.0°
    GRAD,
    /// \brief Zeit in Sekunden als Festkommazahl mit einer Nachkommastelle
    FIXPOINT_01_SEK
};

///
/// \brief Aufzählungstyp BOOL
///
enum BOOL {
    /// \brief 0=AUS
    AUS,
    /// \brief 1=AN
    AN
};

/// \brief Sruktur PARAMETER als Type PARAMETER deklarieren.
///
typedef struct PARAMETER PARAMETER;

/// \brief Die PARAMETER Struktur
///
struct PARAMETER
{
    /// \brief Name des Parameters der angezeigt werden soll
    const char* name;		// Zeiger auf den Anzeigenamen
    /// \brief TYP des Parameters (PERCENT,LIST,INT,UINT,BOOL,GRAD,FIXPOINT_01_SEK)
    unsigned char type;		// Von welchen Typ ist value
    /// \brief Zeiger auf ein Array mit den Einträgen für ein LIST TYP
    char** list_string_array;	// Array mit Namen (nur bei type = LIST)
    /// \brief Minimaler Wert der eingestellt werden kann
    short min;			// Minimaler Wert
    /// \brief Maximaler Wert der eingestellt werden kann
    short max;			// Maximaler Wert
    /// \brief Der Wert dieses Parameters. Die Interpretation hängt vom TYP ab.
    short value;		// Parameter Wert
    /// \brief Benutzerdefiniertes Reserve Byte
    unsigned char user_byte1;	// Benutzerdefiniertes Bytes
    /// \brief Benutzerdefiniertes Reserve Byte
    unsigned char user_byte2;	// Benutzerdefiniertes Bytes
};

/// \brief Sruktur UMENUE als Type UMENUE deklarieren.
///
typedef struct UMENUE UMENUE;

///
/// \brief Die UMENUE Struktur
///
struct UMENUE
{
    /// \brief Name des Menüeintrags der angezeigt werden soll
    const char* name;		    // Zeiger auf den Anzeigenamen
    /// \brief Zeiger auf Array mit Objekten vom TYPE PARAMETER
    PARAMETER* parameter;	    // Zeiger auf Array vom TYPE PARAMETER
    /// \brief Die Anzahl der enthaltenen Parameter
    unsigned char anz_parameter;    // Anzahl der enthaltenen Parameter
    /// \brief Aktuell ausgewählter Parameter
    unsigned char pos;		    // Was ist gerade ausgewählt
};

///
/// \brief Sruktur MENUE als Type MENUE deklarieren.
///
typedef struct MENUE MENUE;

///
/// \brief Die MENUE Struktur
///
struct MENUE
{
    /// \brief Zeiger auf Array mit Objekten vom TYPE UMENU
    UMENUE* umenu;		// Zeiger auf Array vom TYPE UMENU
    /// \brief Die Anzahl der enthaltenen Untermenüs
    unsigned char anz_umenu;	// Anzahl von UMemüs
    /// \brief Aktuell ausgewähltes Untermenü
    unsigned char pos;		// Was ist gerade ausgewählt
};

#endif // MENUE_H

