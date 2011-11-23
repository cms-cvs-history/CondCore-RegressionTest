#include <iostream>
#include <unistd.h>
#include "DataSvc/Ref.h" // v3
#include "CondCore/RegressionTest/interface/SchemaUtils.h"

#include "CondCore/DBCommon/interface/DbConnection.h"
#include "CondCore/DBCommon/interface/DbScopedTransaction.h"
#include "CondCore/DBCommon/interface/DbTransaction.h"
#include "CondCore/DBCommon/interface/Exception.h"
#include "FWCore/PluginManager/interface/PluginManager.h"
#include "FWCore/PluginManager/interface/standard.h"
#include "CondCore/RegressionTest/interface/TestPayloadClass.h"
#include "CondCore/MetaDataService/interface/MetaDataSchemaUtility.h"
#include "CondCore/MetaDataService/interface/MetaData.h"
#include "RelationalAccess/SchemaException.h"
#include "RelationalAccess/ISchema.h"
#include "RelationalAccess/ITable.h"
#include "RelationalAccess/TableDescription.h"
#include "RelationalAccess/ITablePrivilegeManager.h"
#include "RelationalAccess/ICursor.h"
#include "RelationalAccess/IQuery.h"
#include "RelationalAccess/ITableDataEditor.h"
#include "CoralBase/AttributeList.h"
#include "CoralBase/AttributeSpecification.h"
#include "CoralBase/Attribute.h"

class TestFunct {
public :
	cond::DbSession s; 
	TestFunct();
	bool Write(std::string mappingName, int payloadID);
        bool WriteWithIOV(std::string mappingName, int payloadID, int runValidity, bool updateTestMetadata );
        std::pair<int,int> GetMetadata(std::string mappingName);
	bool Read(std::string mappingName);
        bool ReadWithIOV(std::string mappingName, int seed, int runValidity);
	bool ReadAll();
	bool CreateMetaTable();
	bool DropTables(std::string connStr);
	bool DropItem(std::string mappingName);
};
