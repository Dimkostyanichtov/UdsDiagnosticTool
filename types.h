#ifndef TYPES_H
#define TYPES_H

#include <QMap>

const QMap<QString,ushort> PCanUsb = []() {
  QMap<QString, ushort> result;
  result["PCAN_USBBUS1"] = 0x51U;
  result["PCAN_USBBUS2"] = 0x52U;
  result["PCAN_USBBUS3"] = 0x53U;
  result["PCAN_USBBUS4"] = 0x54U;
  result["PCAN_USBBUS5"] = 0x55U;
  result["PCAN_USBBUS6"] = 0x56U;
  result["PCAN_USBBUS7"] = 0x57U;
  result["PCAN_USBBUS8"] = 0x58U;
  result["PCAN_USBBUS9"] = 0x509U;
  result["PCAN_USBBUS10"] = 0x50AU;
  result["PCAN_USBBUS11"] = 0x50BU;
  result["PCAN_USBBUS12"] = 0x50CU;
  result["PCAN_USBBUS13"] = 0x50DU;
  result["PCAN_USBBUS14"] = 0x50EU;
  result["PCAN_USBBUS15"] = 0x50FU;
  result["PCAN_USBBUS16"] = 0x510U;

  result["PCAN_PCIBUS1"] = 0x41U;
  result["PCAN_PCIBUS2"] = 0x42U;
  result["PCAN_PCIBUS3"] = 0x43U;
  result["PCAN_PCIBUS4"] = 0x44U;
  result["PCAN_PCIBUS5"] = 0x45U;
  result["PCAN_PCIBUS6"] = 0x46U;
  result["PCAN_PCIBUS7"] = 0x47U;
  result["PCAN_PCIBUS8"] = 0x48U;
  result["PCAN_PCIBUS9"] = 0x409U;
  result["PCAN_PCIBUS10"] = 0x40AU;
  result["PCAN_PCIBUS11"] = 0x40BU;
  result["PCAN_PCIBUS12"] = 0x40CU;
  result["PCAN_PCIBUS13"] = 0x40DU;
  result["PCAN_PCIBUS14"] = 0x40EU;
  result["PCAN_PCIBUS15"] = 0x40FU;
  result["PCAN_PCIBUS16"] = 0x410U;
  return result;
}();

const QMap<QString,ushort> PCanSpeed = []() {
  QMap<QString, ushort> result;
  result["PCAN_BAUD_1M"] = 0x0014U;
  result["PCAN_BAUD_800K"] = 0x0016U;
  result["PCAN_BAUD_500K"] = 0x001CU;
  result["PCAN_BAUD_250K"] = 0x011CU;
  result["PCAN_BAUD_125K"] = 0x031CU;
  result["PCAN_BAUD_100K"] = 0x432FU;
  result["PCAN_BAUD_95K"] = 0xC34EU;
  result["PCAN_BAUD_83K"] = 0x852BU;
  result["PCAN_BAUD_50K"] = 0x472FU;
  result["PCAN_BAUD_47K"] = 0x1414U;
  result["PCAN_BAUD_33K"] = 0x8B2FU;
  result["PCAN_BAUD_20K"] = 0x532FU;
  result["PCAN_BAUD_10K"] = 0x672FU;
  result["PCAN_BAUD_5K"] = 0x7F7FU;
  result["PCAN_BAUD_500K_75p"] = 0x003AU;
  return result;
}();

#endif // TYPES_H
