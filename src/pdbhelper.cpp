#include "pdbhelper.h"

PDBHelper::PDBHelper(QObject *parent) : QObject(parent)
{

}

int PDBHelper::sqliteDBMemFile(QString filename, bool save ){
    int ret = -1;
    if(filename.isNull() || filename.isEmpty() ) return ret;

    QVariant v = m_pDB->driver()->handle();
    if (v.isValid() && qstrcmp(v.typeName(), "sqlite3*")==0) {
        // v.data() returns a pointer to the handle
        sqlite3 *handle = *static_cast<sqlite3 **>(v.data());
        if (handle != 0) { // check that it is not NULL
            sqlite3 * pInMemory = handle;
            const char * zFilename = filename.toLocal8Bit().data();
            int rc; /* Function return code */
            sqlite3 *pFile; /* Database connection opened on zFilename */
            sqlite3_backup *pBackup; /* Backup object used to copy data */
            sqlite3 *pTo; /* Database to copy to (pFile or pInMemory) */
            sqlite3 *pFrom; /* Database to copy from (pFile or pInMemory) */

            rc = sqlite3_open( zFilename, &pFile );
            if( rc==SQLITE_OK ){
              pFrom = ( save ? pInMemory : pFile);
              pTo = ( save ? pFile : pInMemory);

              pBackup = sqlite3_backup_init(pTo, "main", pFrom, "main");
              if( pBackup ){
                      (void)sqlite3_backup_step(pBackup, -1);
                      (void)sqlite3_backup_finish(pBackup);
              }
              rc = sqlite3_errcode(pTo);
            }

            (void)sqlite3_close(pFile);

            if( rc == SQLITE_OK ) ret = true;
        }
    }
    return ret;
}
