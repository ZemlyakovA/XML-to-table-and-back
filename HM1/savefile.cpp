#include "savefile.h"
#include <QMessageBox>
#include "QStandardItem"

SaveFile::SaveFile()
{

}


void SaveFile::writeFile(QMap<qint8, Student> *map)
{
    QString filename = QFileDialog::getSaveFileName(nullptr, "save Xml", ".", "Xml files (*.xml)");

    if(filename != "")
    {
        QFile file(filename);
        file.open(QIODevice::WriteOnly);

        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);

        xmlWriter.writeStartDocument();
        xmlWriter.writeStartElement("students");
        for(qint8 i=0; i< map->size(); i++)
        {
            xmlWriter.writeStartElement("item", "student");
            xmlWriter.writeStartElement("name");
            xmlWriter.writeCharacters(map->find(i).value().fio());
            xmlWriter.writeEndElement();
            xmlWriter.writeStartElement("group");
            xmlWriter.writeCharacters(map->find(i).value().group());
            xmlWriter.writeEndElement();
            xmlWriter.writeStartElement("card");
            xmlWriter.writeCharacters(map->find(i).value().zach());
            xmlWriter.writeEndElement();
            xmlWriter.writeEndElement();
        }
        xmlWriter.writeEndElement();
        xmlWriter.writeEndDocument();
    }
}
