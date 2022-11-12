/* WARNING: This is a generated file.
 * Any manual changes will be overwritten. */

#include "include/nodeset.h"


/* Kinematics - ns=1;i=2130 */

static UA_StatusCode function_nodeset_0_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Kinematics");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2130LU),
UA_NODEID_NUMERIC(ns[0], 85LU),
UA_NODEID_NUMERIC(ns[0], 35LU),
UA_QUALIFIEDNAME(ns[1], "Kinematics"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_0_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2130LU)
);
}

/* KinematicData - ns=1;i=2118 */

static UA_StatusCode function_nodeset_1_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectTypeAttributes attr = UA_ObjectTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "KinematicData");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "KinematicData");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECTTYPE,
UA_NODEID_NUMERIC(ns[1], 2118LU),
UA_NODEID_NUMERIC(ns[0], 58LU),
UA_NODEID_NUMERIC(ns[0], 45LU),
UA_QUALIFIEDNAME(ns[1], "KinematicData"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTTYPEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_1_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2118LU)
);
}

/* Inverse - ns=1;i=2141 */

static UA_StatusCode function_nodeset_2_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Inverse");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "KinematicData");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2141LU),
UA_NODEID_NUMERIC(ns[1], 2130LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Inverse"),
UA_NODEID_NUMERIC(ns[1], 2118LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_2_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2141LU)
);
}

/* Velocities - ns=1;i=2146 */

static UA_StatusCode function_nodeset_3_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Velocities");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2146LU),
UA_NODEID_NUMERIC(ns[1], 2141LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Velocities"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_3_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2146LU)
);
}

/* RearRight - ns=1;i=2150 */

static UA_StatusCode function_nodeset_4_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "RearRight");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "RearRight");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2150LU),
UA_NODEID_NUMERIC(ns[1], 2146LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "RearRight"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_4_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2150LU)
);
}

/* RearLeft - ns=1;i=2149 */

static UA_StatusCode function_nodeset_5_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "RearLeft");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "RearLeft");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2149LU),
UA_NODEID_NUMERIC(ns[1], 2146LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "RearLeft"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_5_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2149LU)
);
}

/* FrontRight - ns=1;i=2148 */

static UA_StatusCode function_nodeset_6_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "FrontRight");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "FrontRight");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2148LU),
UA_NODEID_NUMERIC(ns[1], 2146LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "FrontRight"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_6_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2148LU)
);
}

/* FrontLeft - ns=1;i=2147 */

static UA_StatusCode function_nodeset_7_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "FrontLeft");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "FrontLeft");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2147LU),
UA_NODEID_NUMERIC(ns[1], 2146LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "FrontLeft"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_7_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2147LU)
);
}

/* Motion - ns=1;i=2142 */

static UA_StatusCode function_nodeset_8_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Motion");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2142LU),
UA_NODEID_NUMERIC(ns[1], 2141LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Motion"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_8_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2142LU)
);
}

/* Z - ns=1;i=2145 */

static UA_StatusCode function_nodeset_9_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Z");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Z");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2145LU),
UA_NODEID_NUMERIC(ns[1], 2142LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Z"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_9_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2145LU)
);
}

/* Y - ns=1;i=2144 */

static UA_StatusCode function_nodeset_10_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Y");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Y");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2144LU),
UA_NODEID_NUMERIC(ns[1], 2142LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Y"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_10_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2144LU)
);
}

/* X - ns=1;i=2143 */

static UA_StatusCode function_nodeset_11_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "X");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "X");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2143LU),
UA_NODEID_NUMERIC(ns[1], 2142LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "X"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_11_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2143LU)
);
}

/* Forward - ns=1;i=2131 */

static UA_StatusCode function_nodeset_12_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Forward");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "KinematicData");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2131LU),
UA_NODEID_NUMERIC(ns[1], 2130LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Forward"),
UA_NODEID_NUMERIC(ns[1], 2118LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_12_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2131LU)
);
}

/* Velocities - ns=1;i=2136 */

static UA_StatusCode function_nodeset_13_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Velocities");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2136LU),
UA_NODEID_NUMERIC(ns[1], 2131LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Velocities"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_13_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2136LU)
);
}

/* RearRight - ns=1;i=2140 */

static UA_StatusCode function_nodeset_14_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "RearRight");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "RearRight");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2140LU),
UA_NODEID_NUMERIC(ns[1], 2136LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "RearRight"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_14_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2140LU)
);
}

/* RearLeft - ns=1;i=2139 */

static UA_StatusCode function_nodeset_15_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "RearLeft");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "RearLeft");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2139LU),
UA_NODEID_NUMERIC(ns[1], 2136LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "RearLeft"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_15_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2139LU)
);
}

/* FrontRight - ns=1;i=2138 */

static UA_StatusCode function_nodeset_16_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "FrontRight");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "FrontRight");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2138LU),
UA_NODEID_NUMERIC(ns[1], 2136LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "FrontRight"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_16_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2138LU)
);
}

/* FrontLeft - ns=1;i=2137 */

static UA_StatusCode function_nodeset_17_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "FrontLeft");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "FrontLeft");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2137LU),
UA_NODEID_NUMERIC(ns[1], 2136LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "FrontLeft"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_17_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2137LU)
);
}

/* Motion - ns=1;i=2132 */

static UA_StatusCode function_nodeset_18_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Motion");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2132LU),
UA_NODEID_NUMERIC(ns[1], 2131LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Motion"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_18_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2132LU)
);
}

/* Z - ns=1;i=2135 */

static UA_StatusCode function_nodeset_19_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Z");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Z");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2135LU),
UA_NODEID_NUMERIC(ns[1], 2132LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Z"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_19_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2135LU)
);
}

/* Y - ns=1;i=2134 */

static UA_StatusCode function_nodeset_20_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Y");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Y");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2134LU),
UA_NODEID_NUMERIC(ns[1], 2132LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Y"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_20_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2134LU)
);
}

/* X - ns=1;i=2133 */

static UA_StatusCode function_nodeset_21_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "X");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "X");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2133LU),
UA_NODEID_NUMERIC(ns[1], 2132LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "X"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_21_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2133LU)
);
}

/* Velocities - ns=1;i=2125 */

static UA_StatusCode function_nodeset_22_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Velocities");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2125LU),
UA_NODEID_NUMERIC(ns[1], 2118LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Velocities"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2125LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_22_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2125LU)
);
}

/* RearRight - ns=1;i=2129 */

static UA_StatusCode function_nodeset_23_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "RearRight");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "RearRight");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2129LU),
UA_NODEID_NUMERIC(ns[1], 2125LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "RearRight"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2129LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_23_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2129LU)
);
}

/* RearLeft - ns=1;i=2128 */

static UA_StatusCode function_nodeset_24_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "RearLeft");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "RearLeft");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2128LU),
UA_NODEID_NUMERIC(ns[1], 2125LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "RearLeft"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2128LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_24_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2128LU)
);
}

/* FrontRight - ns=1;i=2127 */

static UA_StatusCode function_nodeset_25_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "FrontRight");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "FrontRight");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2127LU),
UA_NODEID_NUMERIC(ns[1], 2125LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "FrontRight"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2127LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_25_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2127LU)
);
}

/* FrontLeft - ns=1;i=2126 */

static UA_StatusCode function_nodeset_26_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "FrontLeft");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "FrontLeft");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2126LU),
UA_NODEID_NUMERIC(ns[1], 2125LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "FrontLeft"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2126LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_26_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2126LU)
);
}

/* Motion - ns=1;i=2119 */

static UA_StatusCode function_nodeset_27_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Motion");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2119LU),
UA_NODEID_NUMERIC(ns[1], 2118LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Motion"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2119LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_27_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2119LU)
);
}

/* Z - ns=1;i=2124 */

static UA_StatusCode function_nodeset_28_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Z");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Z");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2124LU),
UA_NODEID_NUMERIC(ns[1], 2119LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Z"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2124LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_28_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2124LU)
);
}

/* Y - ns=1;i=2123 */

static UA_StatusCode function_nodeset_29_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Y");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Y");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2123LU),
UA_NODEID_NUMERIC(ns[1], 2119LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Y"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2123LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_29_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2123LU)
);
}

/* X - ns=1;i=2122 */

static UA_StatusCode function_nodeset_30_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "X");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "X");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2122LU),
UA_NODEID_NUMERIC(ns[1], 2119LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "X"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2122LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_30_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2122LU)
);
}

/* SoftwareVersion - ns=1;i=2117 */

static UA_StatusCode function_nodeset_31_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 4;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7LU);
attr.displayName = UA_LOCALIZEDTEXT("", "SoftwareVersion");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "SoftwareVersion");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2117LU),
UA_NODEID_NUMERIC(ns[0], 85LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "SoftwareVersion"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_31_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2117LU)
);
}

/* ODrives - ns=1;i=2024 */

static UA_StatusCode function_nodeset_32_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ODrives");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2024LU),
UA_NODEID_NUMERIC(ns[0], 85LU),
UA_NODEID_NUMERIC(ns[0], 35LU),
UA_QUALIFIEDNAME(ns[1], "ODrives"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_32_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2024LU)
);
}

/* ODrive - ns=1;i=2001 */

static UA_StatusCode function_nodeset_33_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectTypeAttributes attr = UA_ObjectTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ODrive");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "ODrive");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECTTYPE,
UA_NODEID_NUMERIC(ns[1], 2001LU),
UA_NODEID_NUMERIC(ns[0], 58LU),
UA_NODEID_NUMERIC(ns[0], 45LU),
UA_QUALIFIEDNAME(ns[1], "ODrive"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTTYPEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_33_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2001LU)
);
}

/* RearRight - ns=1;i=2094 */

static UA_StatusCode function_nodeset_34_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "RearRight");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "ODrive");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2094LU),
UA_NODEID_NUMERIC(ns[1], 2024LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "RearRight"),
UA_NODEID_NUMERIC(ns[1], 2001LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_34_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2094LU)
);
}

/* VbusVoltage - ns=1;i=2116 */

static UA_StatusCode function_nodeset_35_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "VbusVoltage");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "VbusVoltage");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2116LU),
UA_NODEID_NUMERIC(ns[1], 2094LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "VbusVoltage"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_35_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2116LU)
);
}

/* SensorlessEstimates - ns=1;i=2113 */

static UA_StatusCode function_nodeset_36_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "SensorlessEstimates");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2113LU),
UA_NODEID_NUMERIC(ns[1], 2094LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Sensorless"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_36_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2113LU)
);
}

/* Velocity - ns=1;i=2115 */

static UA_StatusCode function_nodeset_37_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Velocity");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Velocity");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2115LU),
UA_NODEID_NUMERIC(ns[1], 2113LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Velocity"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_37_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2115LU)
);
}

/* Position - ns=1;i=2114 */

static UA_StatusCode function_nodeset_38_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Position");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Position");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2114LU),
UA_NODEID_NUMERIC(ns[1], 2113LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Position"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_38_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2114LU)
);
}

/* IQ - ns=1;i=2110 */

static UA_StatusCode function_nodeset_39_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "IQ");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2110LU),
UA_NODEID_NUMERIC(ns[1], 2094LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "IQ"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_39_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2110LU)
);
}

/* Setpoint - ns=1;i=2112 */

static UA_StatusCode function_nodeset_40_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Setpoint");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Setpoint");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2112LU),
UA_NODEID_NUMERIC(ns[1], 2110LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Setpoint"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_40_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2112LU)
);
}

/* Measured - ns=1;i=2111 */

static UA_StatusCode function_nodeset_41_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Measured");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Measured");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2111LU),
UA_NODEID_NUMERIC(ns[1], 2110LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Measured"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_41_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2111LU)
);
}

/* Error - ns=1;i=2103 */

static UA_StatusCode function_nodeset_42_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Error");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2103LU),
UA_NODEID_NUMERIC(ns[1], 2094LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Error"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_42_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2103LU)
);
}

/* Sensorless - ns=1;i=2109 */

static UA_StatusCode function_nodeset_43_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Sensorless");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Sensorless");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2109LU),
UA_NODEID_NUMERIC(ns[1], 2103LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Sensorless"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_43_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2109LU)
);
}

/* Motor - ns=1;i=2108 */

static UA_StatusCode function_nodeset_44_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 9LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Motor");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Motor");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2108LU),
UA_NODEID_NUMERIC(ns[1], 2103LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Motor"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_44_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2108LU)
);
}

/* Encoder - ns=1;i=2107 */

static UA_StatusCode function_nodeset_45_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Encoder");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Encoder");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2107LU),
UA_NODEID_NUMERIC(ns[1], 2103LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Encoder"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_45_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2107LU)
);
}

/* Controller - ns=1;i=2106 */

static UA_StatusCode function_nodeset_46_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 3LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Controller");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Controller");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2106LU),
UA_NODEID_NUMERIC(ns[1], 2103LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Controller"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_46_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2106LU)
);
}

/* Board - ns=1;i=2105 */

static UA_StatusCode function_nodeset_47_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 3LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Board");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Board");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2105LU),
UA_NODEID_NUMERIC(ns[1], 2103LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Board"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_47_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2105LU)
);
}

/* Axis - ns=1;i=2104 */

static UA_StatusCode function_nodeset_48_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Axis");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Axis");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2104LU),
UA_NODEID_NUMERIC(ns[1], 2103LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Axis"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_48_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2104LU)
);
}

/* EncoderEstimates - ns=1;i=2100 */

static UA_StatusCode function_nodeset_49_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "EncoderEstimates");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2100LU),
UA_NODEID_NUMERIC(ns[1], 2094LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "EncoderEstimates"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_49_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2100LU)
);
}

/* Velocity - ns=1;i=2102 */

static UA_StatusCode function_nodeset_50_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Velocity");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Velocity");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2102LU),
UA_NODEID_NUMERIC(ns[1], 2100LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Velocity"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_50_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2102LU)
);
}

/* Position - ns=1;i=2101 */

static UA_StatusCode function_nodeset_51_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Position");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Position");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2101LU),
UA_NODEID_NUMERIC(ns[1], 2100LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Position"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_51_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2101LU)
);
}

/* EncoderCounts - ns=1;i=2097 */

static UA_StatusCode function_nodeset_52_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "EncoderCounts");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2097LU),
UA_NODEID_NUMERIC(ns[1], 2094LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "EncoderCounts"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_52_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2097LU)
);
}

/* Shadow - ns=1;i=2099 */

static UA_StatusCode function_nodeset_53_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 6LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Shadow");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Shadow");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2099LU),
UA_NODEID_NUMERIC(ns[1], 2097LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Shadow"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_53_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2099LU)
);
}

/* CPR - ns=1;i=2098 */

static UA_StatusCode function_nodeset_54_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 6LU);
attr.displayName = UA_LOCALIZEDTEXT("", "CPR");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "CPR");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2098LU),
UA_NODEID_NUMERIC(ns[1], 2097LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "CPR"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_54_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2098LU)
);
}

/* ControllerStatus - ns=1;i=2096 */

static UA_StatusCode function_nodeset_55_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 3LU);
attr.displayName = UA_LOCALIZEDTEXT("", "ControllerStatus");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "ControllerStatus");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2096LU),
UA_NODEID_NUMERIC(ns[1], 2094LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "ControllerStatus"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_55_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2096LU)
);
}

/* AxisState - ns=1;i=2095 */

static UA_StatusCode function_nodeset_56_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 3LU);
attr.displayName = UA_LOCALIZEDTEXT("", "AxisState");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "AxisState");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2095LU),
UA_NODEID_NUMERIC(ns[1], 2094LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "AxisState"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_56_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2095LU)
);
}

/* RearLeft - ns=1;i=2071 */

static UA_StatusCode function_nodeset_57_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "RearLeft");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "ODrive");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2071LU),
UA_NODEID_NUMERIC(ns[1], 2024LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "RearLeft"),
UA_NODEID_NUMERIC(ns[1], 2001LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_57_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2071LU)
);
}

/* VbusVoltage - ns=1;i=2093 */

static UA_StatusCode function_nodeset_58_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "VbusVoltage");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "VbusVoltage");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2093LU),
UA_NODEID_NUMERIC(ns[1], 2071LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "VbusVoltage"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_58_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2093LU)
);
}

/* SensorlessEstimates - ns=1;i=2090 */

static UA_StatusCode function_nodeset_59_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "SensorlessEstimates");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2090LU),
UA_NODEID_NUMERIC(ns[1], 2071LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Sensorless"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_59_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2090LU)
);
}

/* Velocity - ns=1;i=2092 */

static UA_StatusCode function_nodeset_60_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Velocity");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Velocity");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2092LU),
UA_NODEID_NUMERIC(ns[1], 2090LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Velocity"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_60_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2092LU)
);
}

/* Position - ns=1;i=2091 */

static UA_StatusCode function_nodeset_61_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Position");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Position");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2091LU),
UA_NODEID_NUMERIC(ns[1], 2090LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Position"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_61_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2091LU)
);
}

/* IQ - ns=1;i=2087 */

static UA_StatusCode function_nodeset_62_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "IQ");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2087LU),
UA_NODEID_NUMERIC(ns[1], 2071LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "IQ"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_62_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2087LU)
);
}

/* Setpoint - ns=1;i=2089 */

static UA_StatusCode function_nodeset_63_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Setpoint");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Setpoint");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2089LU),
UA_NODEID_NUMERIC(ns[1], 2087LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Setpoint"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_63_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2089LU)
);
}

/* Measured - ns=1;i=2088 */

static UA_StatusCode function_nodeset_64_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Measured");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Measured");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2088LU),
UA_NODEID_NUMERIC(ns[1], 2087LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Measured"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_64_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2088LU)
);
}

/* Error - ns=1;i=2080 */

static UA_StatusCode function_nodeset_65_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Error");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2080LU),
UA_NODEID_NUMERIC(ns[1], 2071LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Error"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_65_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2080LU)
);
}

/* Sensorless - ns=1;i=2086 */

static UA_StatusCode function_nodeset_66_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Sensorless");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Sensorless");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2086LU),
UA_NODEID_NUMERIC(ns[1], 2080LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Sensorless"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_66_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2086LU)
);
}

/* Motor - ns=1;i=2085 */

static UA_StatusCode function_nodeset_67_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 9LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Motor");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Motor");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2085LU),
UA_NODEID_NUMERIC(ns[1], 2080LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Motor"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_67_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2085LU)
);
}

/* Encoder - ns=1;i=2084 */

static UA_StatusCode function_nodeset_68_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Encoder");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Encoder");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2084LU),
UA_NODEID_NUMERIC(ns[1], 2080LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Encoder"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_68_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2084LU)
);
}

/* Controller - ns=1;i=2083 */

static UA_StatusCode function_nodeset_69_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 3LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Controller");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Controller");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2083LU),
UA_NODEID_NUMERIC(ns[1], 2080LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Controller"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_69_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2083LU)
);
}

/* Board - ns=1;i=2082 */

static UA_StatusCode function_nodeset_70_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 3LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Board");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Board");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2082LU),
UA_NODEID_NUMERIC(ns[1], 2080LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Board"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_70_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2082LU)
);
}

/* Axis - ns=1;i=2081 */

static UA_StatusCode function_nodeset_71_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Axis");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Axis");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2081LU),
UA_NODEID_NUMERIC(ns[1], 2080LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Axis"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_71_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2081LU)
);
}

/* EncoderEstimates - ns=1;i=2077 */

static UA_StatusCode function_nodeset_72_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "EncoderEstimates");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2077LU),
UA_NODEID_NUMERIC(ns[1], 2071LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "EncoderEstimates"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_72_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2077LU)
);
}

/* Velocity - ns=1;i=2079 */

static UA_StatusCode function_nodeset_73_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Velocity");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Velocity");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2079LU),
UA_NODEID_NUMERIC(ns[1], 2077LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Velocity"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_73_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2079LU)
);
}

/* Position - ns=1;i=2078 */

static UA_StatusCode function_nodeset_74_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Position");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Position");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2078LU),
UA_NODEID_NUMERIC(ns[1], 2077LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Position"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_74_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2078LU)
);
}

/* EncoderCounts - ns=1;i=2074 */

static UA_StatusCode function_nodeset_75_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "EncoderCounts");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2074LU),
UA_NODEID_NUMERIC(ns[1], 2071LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "EncoderCounts"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_75_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2074LU)
);
}

/* Shadow - ns=1;i=2076 */

static UA_StatusCode function_nodeset_76_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 6LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Shadow");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Shadow");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2076LU),
UA_NODEID_NUMERIC(ns[1], 2074LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Shadow"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_76_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2076LU)
);
}

/* CPR - ns=1;i=2075 */

static UA_StatusCode function_nodeset_77_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 6LU);
attr.displayName = UA_LOCALIZEDTEXT("", "CPR");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "CPR");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2075LU),
UA_NODEID_NUMERIC(ns[1], 2074LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "CPR"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_77_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2075LU)
);
}

/* ControllerStatus - ns=1;i=2073 */

static UA_StatusCode function_nodeset_78_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 3LU);
attr.displayName = UA_LOCALIZEDTEXT("", "ControllerStatus");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "ControllerStatus");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2073LU),
UA_NODEID_NUMERIC(ns[1], 2071LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "ControllerStatus"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_78_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2073LU)
);
}

/* AxisState - ns=1;i=2072 */

static UA_StatusCode function_nodeset_79_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 3LU);
attr.displayName = UA_LOCALIZEDTEXT("", "AxisState");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "AxisState");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2072LU),
UA_NODEID_NUMERIC(ns[1], 2071LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "AxisState"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_79_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2072LU)
);
}

/* FrontRight - ns=1;i=2048 */

static UA_StatusCode function_nodeset_80_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "FrontRight");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "ODrive");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2048LU),
UA_NODEID_NUMERIC(ns[1], 2024LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "FrontRight"),
UA_NODEID_NUMERIC(ns[1], 2001LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_80_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2048LU)
);
}

/* VbusVoltage - ns=1;i=2070 */

static UA_StatusCode function_nodeset_81_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "VbusVoltage");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "VbusVoltage");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2070LU),
UA_NODEID_NUMERIC(ns[1], 2048LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "VbusVoltage"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_81_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2070LU)
);
}

/* SensorlessEstimates - ns=1;i=2067 */

static UA_StatusCode function_nodeset_82_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "SensorlessEstimates");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2067LU),
UA_NODEID_NUMERIC(ns[1], 2048LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Sensorless"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_82_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2067LU)
);
}

/* Velocity - ns=1;i=2069 */

static UA_StatusCode function_nodeset_83_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Velocity");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Velocity");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2069LU),
UA_NODEID_NUMERIC(ns[1], 2067LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Velocity"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_83_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2069LU)
);
}

/* Position - ns=1;i=2068 */

static UA_StatusCode function_nodeset_84_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Position");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Position");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2068LU),
UA_NODEID_NUMERIC(ns[1], 2067LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Position"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_84_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2068LU)
);
}

/* IQ - ns=1;i=2064 */

static UA_StatusCode function_nodeset_85_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "IQ");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2064LU),
UA_NODEID_NUMERIC(ns[1], 2048LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "IQ"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_85_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2064LU)
);
}

/* Setpoint - ns=1;i=2066 */

static UA_StatusCode function_nodeset_86_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Setpoint");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Setpoint");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2066LU),
UA_NODEID_NUMERIC(ns[1], 2064LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Setpoint"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_86_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2066LU)
);
}

/* Measured - ns=1;i=2065 */

static UA_StatusCode function_nodeset_87_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Measured");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Measured");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2065LU),
UA_NODEID_NUMERIC(ns[1], 2064LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Measured"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_87_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2065LU)
);
}

/* Error - ns=1;i=2057 */

static UA_StatusCode function_nodeset_88_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Error");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2057LU),
UA_NODEID_NUMERIC(ns[1], 2048LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Error"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_88_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2057LU)
);
}

/* Sensorless - ns=1;i=2063 */

static UA_StatusCode function_nodeset_89_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Sensorless");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Sensorless");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2063LU),
UA_NODEID_NUMERIC(ns[1], 2057LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Sensorless"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_89_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2063LU)
);
}

/* Motor - ns=1;i=2062 */

static UA_StatusCode function_nodeset_90_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 9LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Motor");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Motor");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2062LU),
UA_NODEID_NUMERIC(ns[1], 2057LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Motor"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_90_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2062LU)
);
}

/* Encoder - ns=1;i=2061 */

static UA_StatusCode function_nodeset_91_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Encoder");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Encoder");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2061LU),
UA_NODEID_NUMERIC(ns[1], 2057LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Encoder"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_91_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2061LU)
);
}

/* Controller - ns=1;i=2060 */

static UA_StatusCode function_nodeset_92_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 3LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Controller");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Controller");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2060LU),
UA_NODEID_NUMERIC(ns[1], 2057LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Controller"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_92_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2060LU)
);
}

/* Board - ns=1;i=2059 */

static UA_StatusCode function_nodeset_93_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 3LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Board");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Board");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2059LU),
UA_NODEID_NUMERIC(ns[1], 2057LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Board"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_93_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2059LU)
);
}

/* Axis - ns=1;i=2058 */

static UA_StatusCode function_nodeset_94_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Axis");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Axis");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2058LU),
UA_NODEID_NUMERIC(ns[1], 2057LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Axis"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_94_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2058LU)
);
}

/* EncoderEstimates - ns=1;i=2054 */

static UA_StatusCode function_nodeset_95_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "EncoderEstimates");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2054LU),
UA_NODEID_NUMERIC(ns[1], 2048LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "EncoderEstimates"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_95_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2054LU)
);
}

/* Velocity - ns=1;i=2056 */

static UA_StatusCode function_nodeset_96_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Velocity");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Velocity");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2056LU),
UA_NODEID_NUMERIC(ns[1], 2054LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Velocity"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_96_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2056LU)
);
}

/* Position - ns=1;i=2055 */

static UA_StatusCode function_nodeset_97_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Position");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Position");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2055LU),
UA_NODEID_NUMERIC(ns[1], 2054LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Position"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_97_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2055LU)
);
}

/* EncoderCounts - ns=1;i=2051 */

static UA_StatusCode function_nodeset_98_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "EncoderCounts");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2051LU),
UA_NODEID_NUMERIC(ns[1], 2048LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "EncoderCounts"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_98_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2051LU)
);
}

/* Shadow - ns=1;i=2053 */

static UA_StatusCode function_nodeset_99_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 6LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Shadow");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Shadow");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2053LU),
UA_NODEID_NUMERIC(ns[1], 2051LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Shadow"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_99_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2053LU)
);
}

/* CPR - ns=1;i=2052 */

static UA_StatusCode function_nodeset_100_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 6LU);
attr.displayName = UA_LOCALIZEDTEXT("", "CPR");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "CPR");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2052LU),
UA_NODEID_NUMERIC(ns[1], 2051LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "CPR"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_100_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2052LU)
);
}

/* ControllerStatus - ns=1;i=2050 */

static UA_StatusCode function_nodeset_101_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 3LU);
attr.displayName = UA_LOCALIZEDTEXT("", "ControllerStatus");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "ControllerStatus");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2050LU),
UA_NODEID_NUMERIC(ns[1], 2048LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "ControllerStatus"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_101_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2050LU)
);
}

/* AxisState - ns=1;i=2049 */

static UA_StatusCode function_nodeset_102_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 3LU);
attr.displayName = UA_LOCALIZEDTEXT("", "AxisState");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "AxisState");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2049LU),
UA_NODEID_NUMERIC(ns[1], 2048LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "AxisState"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_102_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2049LU)
);
}

/* FrontLeft - ns=1;i=2025 */

static UA_StatusCode function_nodeset_103_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "FrontLeft");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "ODrive");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2025LU),
UA_NODEID_NUMERIC(ns[1], 2024LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "FrontLeft"),
UA_NODEID_NUMERIC(ns[1], 2001LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_103_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2025LU)
);
}

/* VbusVoltage - ns=1;i=2047 */

static UA_StatusCode function_nodeset_104_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "VbusVoltage");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "VbusVoltage");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2047LU),
UA_NODEID_NUMERIC(ns[1], 2025LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "VbusVoltage"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_104_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2047LU)
);
}

/* SensorlessEstimates - ns=1;i=2044 */

static UA_StatusCode function_nodeset_105_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "SensorlessEstimates");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2044LU),
UA_NODEID_NUMERIC(ns[1], 2025LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Sensorless"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_105_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2044LU)
);
}

/* Velocity - ns=1;i=2046 */

static UA_StatusCode function_nodeset_106_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Velocity");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Velocity");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2046LU),
UA_NODEID_NUMERIC(ns[1], 2044LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Velocity"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_106_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2046LU)
);
}

/* Position - ns=1;i=2045 */

static UA_StatusCode function_nodeset_107_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Position");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Position");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2045LU),
UA_NODEID_NUMERIC(ns[1], 2044LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Position"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_107_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2045LU)
);
}

/* IQ - ns=1;i=2041 */

static UA_StatusCode function_nodeset_108_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "IQ");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2041LU),
UA_NODEID_NUMERIC(ns[1], 2025LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "IQ"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_108_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2041LU)
);
}

/* Setpoint - ns=1;i=2043 */

static UA_StatusCode function_nodeset_109_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Setpoint");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Setpoint");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2043LU),
UA_NODEID_NUMERIC(ns[1], 2041LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Setpoint"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_109_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2043LU)
);
}

/* Measured - ns=1;i=2042 */

static UA_StatusCode function_nodeset_110_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Measured");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Measured");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2042LU),
UA_NODEID_NUMERIC(ns[1], 2041LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Measured"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_110_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2042LU)
);
}

/* Error - ns=1;i=2034 */

static UA_StatusCode function_nodeset_111_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Error");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2034LU),
UA_NODEID_NUMERIC(ns[1], 2025LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Error"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_111_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2034LU)
);
}

/* Sensorless - ns=1;i=2040 */

static UA_StatusCode function_nodeset_112_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Sensorless");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Sensorless");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2040LU),
UA_NODEID_NUMERIC(ns[1], 2034LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Sensorless"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_112_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2040LU)
);
}

/* Motor - ns=1;i=2039 */

static UA_StatusCode function_nodeset_113_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 9LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Motor");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Motor");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2039LU),
UA_NODEID_NUMERIC(ns[1], 2034LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Motor"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_113_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2039LU)
);
}

/* Encoder - ns=1;i=2038 */

static UA_StatusCode function_nodeset_114_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Encoder");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Encoder");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2038LU),
UA_NODEID_NUMERIC(ns[1], 2034LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Encoder"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_114_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2038LU)
);
}

/* Controller - ns=1;i=2037 */

static UA_StatusCode function_nodeset_115_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 3LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Controller");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Controller");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2037LU),
UA_NODEID_NUMERIC(ns[1], 2034LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Controller"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_115_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2037LU)
);
}

/* Board - ns=1;i=2036 */

static UA_StatusCode function_nodeset_116_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 3LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Board");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Board");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2036LU),
UA_NODEID_NUMERIC(ns[1], 2034LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Board"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_116_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2036LU)
);
}

/* Axis - ns=1;i=2035 */

static UA_StatusCode function_nodeset_117_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Axis");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Axis");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2035LU),
UA_NODEID_NUMERIC(ns[1], 2034LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Axis"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_117_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2035LU)
);
}

/* EncoderEstimates - ns=1;i=2031 */

static UA_StatusCode function_nodeset_118_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "EncoderEstimates");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2031LU),
UA_NODEID_NUMERIC(ns[1], 2025LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "EncoderEstimates"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_118_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2031LU)
);
}

/* Velocity - ns=1;i=2033 */

static UA_StatusCode function_nodeset_119_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Velocity");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Velocity");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2033LU),
UA_NODEID_NUMERIC(ns[1], 2031LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Velocity"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_119_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2033LU)
);
}

/* Position - ns=1;i=2032 */

static UA_StatusCode function_nodeset_120_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Position");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Position");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2032LU),
UA_NODEID_NUMERIC(ns[1], 2031LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Position"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_120_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2032LU)
);
}

/* EncoderCounts - ns=1;i=2028 */

static UA_StatusCode function_nodeset_121_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "EncoderCounts");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2028LU),
UA_NODEID_NUMERIC(ns[1], 2025LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "EncoderCounts"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_121_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2028LU)
);
}

/* Shadow - ns=1;i=2030 */

static UA_StatusCode function_nodeset_122_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 6LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Shadow");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Shadow");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2030LU),
UA_NODEID_NUMERIC(ns[1], 2028LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Shadow"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_122_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2030LU)
);
}

/* CPR - ns=1;i=2029 */

static UA_StatusCode function_nodeset_123_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 6LU);
attr.displayName = UA_LOCALIZEDTEXT("", "CPR");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "CPR");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2029LU),
UA_NODEID_NUMERIC(ns[1], 2028LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "CPR"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_123_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2029LU)
);
}

/* ControllerStatus - ns=1;i=2027 */

static UA_StatusCode function_nodeset_124_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 3LU);
attr.displayName = UA_LOCALIZEDTEXT("", "ControllerStatus");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "ControllerStatus");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2027LU),
UA_NODEID_NUMERIC(ns[1], 2025LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "ControllerStatus"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_124_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2027LU)
);
}

/* AxisState - ns=1;i=2026 */

static UA_StatusCode function_nodeset_125_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 3LU);
attr.displayName = UA_LOCALIZEDTEXT("", "AxisState");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "AxisState");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2026LU),
UA_NODEID_NUMERIC(ns[1], 2025LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "AxisState"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_125_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2026LU)
);
}

/* VbusVoltage - ns=1;i=2023 */

static UA_StatusCode function_nodeset_126_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "VbusVoltage");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "VbusVoltage");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2023LU),
UA_NODEID_NUMERIC(ns[1], 2001LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "VbusVoltage"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2023LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_126_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2023LU)
);
}

/* SensorlessEstimates - ns=1;i=2020 */

static UA_StatusCode function_nodeset_127_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "SensorlessEstimates");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2020LU),
UA_NODEID_NUMERIC(ns[1], 2001LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "SensorlessEstimates"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2020LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_127_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2020LU)
);
}

/* Velocity - ns=1;i=2022 */

static UA_StatusCode function_nodeset_128_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Velocity");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Velocity");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2022LU),
UA_NODEID_NUMERIC(ns[1], 2020LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Velocity"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2022LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_128_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2022LU)
);
}

/* Position - ns=1;i=2021 */

static UA_StatusCode function_nodeset_129_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Position");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Position");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2021LU),
UA_NODEID_NUMERIC(ns[1], 2020LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Position"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2021LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_129_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2021LU)
);
}

/* IQ - ns=1;i=2017 */

static UA_StatusCode function_nodeset_130_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "IQ");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2017LU),
UA_NODEID_NUMERIC(ns[1], 2001LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "IQ"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2017LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_130_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2017LU)
);
}

/* Setpoint - ns=1;i=2019 */

static UA_StatusCode function_nodeset_131_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Setpoint");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Setpoint");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2019LU),
UA_NODEID_NUMERIC(ns[1], 2017LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Setpoint"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2019LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_131_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2019LU)
);
}

/* Measured - ns=1;i=2018 */

static UA_StatusCode function_nodeset_132_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Measured");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Measured");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2018LU),
UA_NODEID_NUMERIC(ns[1], 2017LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Measured"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2018LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_132_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2018LU)
);
}

/* Error - ns=1;i=2010 */

static UA_StatusCode function_nodeset_133_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Error");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2010LU),
UA_NODEID_NUMERIC(ns[1], 2001LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Error"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2010LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_133_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2010LU)
);
}

/* Sensorless - ns=1;i=2016 */

static UA_StatusCode function_nodeset_134_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Sensorless");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Sensorless");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2016LU),
UA_NODEID_NUMERIC(ns[1], 2010LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Sensorless"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2016LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_134_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2016LU)
);
}

/* Motor - ns=1;i=2015 */

static UA_StatusCode function_nodeset_135_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 9LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Motor");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Motor");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2015LU),
UA_NODEID_NUMERIC(ns[1], 2010LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Motor"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2015LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_135_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2015LU)
);
}

/* Encoder - ns=1;i=2014 */

static UA_StatusCode function_nodeset_136_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Encoder");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Encoder");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2014LU),
UA_NODEID_NUMERIC(ns[1], 2010LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Encoder"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2014LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_136_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2014LU)
);
}

/* Controller - ns=1;i=2013 */

static UA_StatusCode function_nodeset_137_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 3LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Controller");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Controller");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2013LU),
UA_NODEID_NUMERIC(ns[1], 2010LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Controller"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2013LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_137_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2013LU)
);
}

/* Board - ns=1;i=2012 */

static UA_StatusCode function_nodeset_138_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 3LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Board");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Board");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2012LU),
UA_NODEID_NUMERIC(ns[1], 2010LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Board"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2012LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_138_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2012LU)
);
}

/* Axis - ns=1;i=2011 */

static UA_StatusCode function_nodeset_139_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Axis");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Axis");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2011LU),
UA_NODEID_NUMERIC(ns[1], 2010LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Axis"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2011LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_139_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2011LU)
);
}

/* EncoderEstimates - ns=1;i=2007 */

static UA_StatusCode function_nodeset_140_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "EncoderEstimates");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2007LU),
UA_NODEID_NUMERIC(ns[1], 2001LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "EncoderEstimates"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2007LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_140_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2007LU)
);
}

/* Velocity - ns=1;i=2009 */

static UA_StatusCode function_nodeset_141_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Velocity");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Velocity");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2009LU),
UA_NODEID_NUMERIC(ns[1], 2007LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Velocity"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2009LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_141_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2009LU)
);
}

/* Position - ns=1;i=2008 */

static UA_StatusCode function_nodeset_142_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Position");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Position");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2008LU),
UA_NODEID_NUMERIC(ns[1], 2007LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Position"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2008LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_142_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2008LU)
);
}

/* EncoderCounts - ns=1;i=2004 */

static UA_StatusCode function_nodeset_143_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "EncoderCounts");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2004LU),
UA_NODEID_NUMERIC(ns[1], 2001LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "EncoderCounts"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2004LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_143_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2004LU)
);
}

/* Shadow - ns=1;i=2006 */

static UA_StatusCode function_nodeset_144_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 6LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Shadow");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Shadow");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2006LU),
UA_NODEID_NUMERIC(ns[1], 2004LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Shadow"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2006LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_144_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2006LU)
);
}

/* CPR - ns=1;i=2005 */

static UA_StatusCode function_nodeset_145_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 6LU);
attr.displayName = UA_LOCALIZEDTEXT("", "CPR");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "CPR");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2005LU),
UA_NODEID_NUMERIC(ns[1], 2004LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "CPR"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2005LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_145_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2005LU)
);
}

/* ControllerStatus - ns=1;i=2003 */

static UA_StatusCode function_nodeset_146_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 3LU);
attr.displayName = UA_LOCALIZEDTEXT("", "ControllerStatus");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "ControllerStatus");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2003LU),
UA_NODEID_NUMERIC(ns[1], 2001LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "ControllerStatus"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2003LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_146_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2003LU)
);
}

/* AxisState - ns=1;i=2002 */

static UA_StatusCode function_nodeset_147_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 3LU);
attr.displayName = UA_LOCALIZEDTEXT("", "AxisState");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "AxisState");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2002LU),
UA_NODEID_NUMERIC(ns[1], 2001LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "AxisState"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2002LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_147_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2002LU)
);
}

UA_StatusCode nodeset(UA_Server *server) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
/* Use namespace ids generated by the server */
UA_UInt16 ns[2];
ns[0] = UA_Server_addNamespace(server, "http://opcfoundation.org/UA/");
ns[1] = UA_Server_addNamespace(server, "http//freeopcua/defaults/modeler");

/* Load custom datatype definitions into the server */
if((retVal = function_nodeset_0_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_1_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_2_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_3_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_4_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_5_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_6_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_7_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_8_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_9_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_10_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_11_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_12_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_13_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_14_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_15_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_16_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_17_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_18_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_19_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_20_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_21_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_22_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_23_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_24_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_25_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_26_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_27_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_28_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_29_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_30_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_31_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_32_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_33_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_34_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_35_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_36_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_37_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_38_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_39_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_40_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_41_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_42_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_43_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_44_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_45_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_46_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_47_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_48_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_49_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_50_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_51_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_52_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_53_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_54_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_55_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_56_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_57_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_58_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_59_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_60_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_61_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_62_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_63_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_64_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_65_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_66_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_67_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_68_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_69_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_70_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_71_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_72_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_73_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_74_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_75_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_76_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_77_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_78_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_79_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_80_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_81_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_82_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_83_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_84_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_85_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_86_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_87_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_88_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_89_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_90_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_91_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_92_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_93_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_94_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_95_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_96_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_97_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_98_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_99_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_100_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_101_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_102_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_103_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_104_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_105_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_106_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_107_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_108_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_109_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_110_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_111_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_112_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_113_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_114_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_115_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_116_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_117_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_118_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_119_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_120_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_121_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_122_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_123_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_124_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_125_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_126_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_127_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_128_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_129_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_130_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_131_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_132_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_133_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_134_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_135_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_136_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_137_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_138_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_139_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_140_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_141_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_142_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_143_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_144_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_145_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_146_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_147_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_147_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_146_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_145_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_144_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_143_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_142_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_141_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_140_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_139_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_138_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_137_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_136_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_135_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_134_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_133_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_132_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_131_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_130_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_129_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_128_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_127_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_126_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_125_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_124_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_123_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_122_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_121_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_120_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_119_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_118_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_117_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_116_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_115_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_114_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_113_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_112_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_111_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_110_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_109_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_108_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_107_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_106_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_105_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_104_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_103_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_102_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_101_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_100_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_99_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_98_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_97_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_96_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_95_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_94_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_93_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_92_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_91_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_90_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_89_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_88_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_87_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_86_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_85_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_84_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_83_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_82_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_81_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_80_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_79_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_78_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_77_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_76_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_75_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_74_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_73_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_72_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_71_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_70_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_69_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_68_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_67_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_66_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_65_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_64_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_63_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_62_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_61_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_60_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_59_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_58_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_57_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_56_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_55_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_54_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_53_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_52_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_51_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_50_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_49_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_48_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_47_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_46_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_45_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_44_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_43_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_42_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_41_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_40_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_39_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_38_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_37_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_36_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_35_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_34_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_33_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_32_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_31_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_30_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_29_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_28_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_27_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_26_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_25_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_24_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_23_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_22_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_21_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_20_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_19_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_18_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_17_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_16_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_15_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_14_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_13_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_12_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_11_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_10_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_9_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_8_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_7_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_6_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_5_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_4_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_3_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_2_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_1_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_0_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}
