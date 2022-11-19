/* WARNING: This is a generated file.
 * Any manual changes will be overwritten. */

#include "include/nodeset.h"


/* ConditionSourceObject - ns=1;s=conditionsource */

static UA_StatusCode function_nodeset_0_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ConditionSourceObject");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "conditionsource"),
UA_NODEID_NUMERIC(ns[0], 85LU),
UA_NODEID_NUMERIC(ns[0], 35LU),
UA_QUALIFIEDNAME(ns[1], "ConditionSourceObject"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_0_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "conditionsource")
);
}

/* Battery - ns=1;s=battery */

static UA_StatusCode function_nodeset_1_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Battery");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "battery"),
UA_NODEID_NUMERIC(ns[0], 85LU),
UA_NODEID_NUMERIC(ns[0], 35LU),
UA_QUALIFIEDNAME(ns[1], "Battery"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_1_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "battery")
);
}

/* Voltage - ns=1;s=battery.voltage */

static UA_StatusCode function_nodeset_2_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Voltage");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Voltage");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "battery.voltage"),
UA_NODEID_STRING(ns[1], "battery"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Voltage"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_2_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "battery.voltage")
);
}

/* SoftwareVersion - ns=1;s=battery.softwareversion */

static UA_StatusCode function_nodeset_3_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 4;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 3LU);
attr.displayName = UA_LOCALIZEDTEXT("", "SoftwareVersion");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "SoftwareVersion");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "battery.softwareversion"),
UA_NODEID_STRING(ns[1], "battery"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "SoftwareVersion"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_3_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "battery.softwareversion")
);
}

/* StateOfCharge - ns=1;s=battery.soc */

static UA_StatusCode function_nodeset_4_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 10LU);
attr.displayName = UA_LOCALIZEDTEXT("", "StateOfCharge");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "StateOfCharge");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "battery.soc"),
UA_NODEID_STRING(ns[1], "battery"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "StateOfCharge"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_4_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "battery.soc")
);
}

/* Kinematics - ns=1;s=kinematics */

static UA_StatusCode function_nodeset_5_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Kinematics");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "kinematics"),
UA_NODEID_NUMERIC(ns[0], 85LU),
UA_NODEID_NUMERIC(ns[0], 35LU),
UA_QUALIFIEDNAME(ns[1], "Kinematics"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_5_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "kinematics")
);
}

/* KinematicData - ns=1;i=2118 */

static UA_StatusCode function_nodeset_6_begin(UA_Server *server, UA_UInt16* ns) {
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

static UA_StatusCode function_nodeset_6_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2118LU)
);
}

/* Inverse - ns=1;s=kinematics.inverse */

static UA_StatusCode function_nodeset_7_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Inverse");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "KinematicData");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "kinematics.inverse"),
UA_NODEID_STRING(ns[1], "kinematics"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Inverse"),
UA_NODEID_NUMERIC(ns[1], 2118LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_7_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "kinematics.inverse")
);
}

/* Velocities - ns=1;s=kinematics.inverse.velocities */

static UA_StatusCode function_nodeset_8_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Velocities");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "kinematics.inverse.velocities"),
UA_NODEID_STRING(ns[1], "kinematics.inverse"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Velocities"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_8_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "kinematics.inverse.velocities")
);
}

/* RearRight - ns=1;s=kinematics.inverse.velocities.rearright */

static UA_StatusCode function_nodeset_9_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "kinematics.inverse.velocities.rearright"),
UA_NODEID_STRING(ns[1], "kinematics.inverse.velocities"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "RearRight"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_9_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "kinematics.inverse.velocities.rearright")
);
}

/* RearLeft - ns=1;s=kinematics.inverse.velocities.rearleft */

static UA_StatusCode function_nodeset_10_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "kinematics.inverse.velocities.rearleft"),
UA_NODEID_STRING(ns[1], "kinematics.inverse.velocities"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "RearLeft"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_10_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "kinematics.inverse.velocities.rearleft")
);
}

/* FrontRight - ns=1;s=kinematics.inverse.velocities.frontright */

static UA_StatusCode function_nodeset_11_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "kinematics.inverse.velocities.frontright"),
UA_NODEID_STRING(ns[1], "kinematics.inverse.velocities"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "FrontRight"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_11_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "kinematics.inverse.velocities.frontright")
);
}

/* FrontLeft - ns=1;s=kinematics.inverse.velocities.frontleft */

static UA_StatusCode function_nodeset_12_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "kinematics.inverse.velocities.frontleft"),
UA_NODEID_STRING(ns[1], "kinematics.inverse.velocities"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "FrontLeft"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_12_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "kinematics.inverse.velocities.frontleft")
);
}

/* Motion - ns=1;s=kinematics.inverse.motion */

static UA_StatusCode function_nodeset_13_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Motion");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "kinematics.inverse.motion"),
UA_NODEID_STRING(ns[1], "kinematics.inverse"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Motion"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_13_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "kinematics.inverse.motion")
);
}

/* Z - ns=1;s=kinematics.inverse.motion.z */

static UA_StatusCode function_nodeset_14_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "kinematics.inverse.motion.z"),
UA_NODEID_STRING(ns[1], "kinematics.inverse.motion"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Z"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_14_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "kinematics.inverse.motion.z")
);
}

/* Y - ns=1;s=kinematics.inverse.motion.y */

static UA_StatusCode function_nodeset_15_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "kinematics.inverse.motion.y"),
UA_NODEID_STRING(ns[1], "kinematics.inverse.motion"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Y"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_15_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "kinematics.inverse.motion.y")
);
}

/* X - ns=1;s=kinematics.inverse.motion.x */

static UA_StatusCode function_nodeset_16_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "kinematics.inverse.motion.x"),
UA_NODEID_STRING(ns[1], "kinematics.inverse.motion"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "X"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_16_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "kinematics.inverse.motion.x")
);
}

/* Forward - ns=1;s=kinematics.forward */

static UA_StatusCode function_nodeset_17_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Forward");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "KinematicData");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "kinematics.forward"),
UA_NODEID_STRING(ns[1], "kinematics"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Forward"),
UA_NODEID_NUMERIC(ns[1], 2118LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_17_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "kinematics.forward")
);
}

/* Velocities - ns=1;s=kinematics.forward.velocities */

static UA_StatusCode function_nodeset_18_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Velocities");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "kinematics.forward.velocities"),
UA_NODEID_STRING(ns[1], "kinematics.forward"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Velocities"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_18_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "kinematics.forward.velocities")
);
}

/* RearRight - ns=1;s=kinematics.forward.velocities.rearright */

static UA_StatusCode function_nodeset_19_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "kinematics.forward.velocities.rearright"),
UA_NODEID_STRING(ns[1], "kinematics.forward.velocities"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "RearRight"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_19_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "kinematics.forward.velocities.rearright")
);
}

/* RearLeft - ns=1;s=kinematics.forward.velocities.rearleft */

static UA_StatusCode function_nodeset_20_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "kinematics.forward.velocities.rearleft"),
UA_NODEID_STRING(ns[1], "kinematics.forward.velocities"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "RearLeft"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_20_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "kinematics.forward.velocities.rearleft")
);
}

/* FrontRight - ns=1;s=kinematics.forward.velocities.frontright */

static UA_StatusCode function_nodeset_21_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "kinematics.forward.velocities.frontright"),
UA_NODEID_STRING(ns[1], "kinematics.forward.velocities"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "FrontRight"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_21_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "kinematics.forward.velocities.frontright")
);
}

/* FrontLeft - ns=1;s=kinematics.forward.velocities.frontleft */

static UA_StatusCode function_nodeset_22_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "kinematics.forward.velocities.frontleft"),
UA_NODEID_STRING(ns[1], "kinematics.forward.velocities"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "FrontLeft"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_22_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "kinematics.forward.velocities.frontleft")
);
}

/* Motion - ns=1;s=kinematics.forward.motion */

static UA_StatusCode function_nodeset_23_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Motion");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "kinematics.forward.motion"),
UA_NODEID_STRING(ns[1], "kinematics.forward"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Motion"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_23_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "kinematics.forward.motion")
);
}

/* Z - ns=1;s=kinematics.forward.motion.z */

static UA_StatusCode function_nodeset_24_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "kinematics.forward.motion.z"),
UA_NODEID_STRING(ns[1], "kinematics.forward.motion"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Z"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_24_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "kinematics.forward.motion.z")
);
}

/* Y - ns=1;s=kinematics.forward.motion.y */

static UA_StatusCode function_nodeset_25_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "kinematics.forward.motion.y"),
UA_NODEID_STRING(ns[1], "kinematics.forward.motion"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Y"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_25_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "kinematics.forward.motion.y")
);
}

/* X - ns=1;s=kinematics.forward.motion.x */

static UA_StatusCode function_nodeset_26_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "kinematics.forward.motion.x"),
UA_NODEID_STRING(ns[1], "kinematics.forward.motion"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "X"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_26_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "kinematics.forward.motion.x")
);
}

/* Velocities - ns=1;i=2125 */

static UA_StatusCode function_nodeset_27_begin(UA_Server *server, UA_UInt16* ns) {
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

static UA_StatusCode function_nodeset_27_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2125LU)
);
}

/* RearRight - ns=1;i=2129 */

static UA_StatusCode function_nodeset_28_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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

static UA_StatusCode function_nodeset_28_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2129LU)
);
}

/* RearLeft - ns=1;i=2128 */

static UA_StatusCode function_nodeset_29_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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

static UA_StatusCode function_nodeset_29_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2128LU)
);
}

/* FrontRight - ns=1;i=2127 */

static UA_StatusCode function_nodeset_30_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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

static UA_StatusCode function_nodeset_30_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2127LU)
);
}

/* FrontLeft - ns=1;i=2126 */

static UA_StatusCode function_nodeset_31_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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

static UA_StatusCode function_nodeset_31_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2126LU)
);
}

/* Motion - ns=1;i=2119 */

static UA_StatusCode function_nodeset_32_begin(UA_Server *server, UA_UInt16* ns) {
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

static UA_StatusCode function_nodeset_32_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2119LU)
);
}

/* Z - ns=1;i=2124 */

static UA_StatusCode function_nodeset_33_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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

static UA_StatusCode function_nodeset_33_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2124LU)
);
}

/* Y - ns=1;i=2123 */

static UA_StatusCode function_nodeset_34_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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

static UA_StatusCode function_nodeset_34_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2123LU)
);
}

/* X - ns=1;i=2122 */

static UA_StatusCode function_nodeset_35_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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

static UA_StatusCode function_nodeset_35_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2122LU)
);
}

/* SoftwareVersion - ns=1;s=softwareversion */

static UA_StatusCode function_nodeset_36_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "softwareversion"),
UA_NODEID_NUMERIC(ns[0], 85LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "SoftwareVersion"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_36_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "softwareversion")
);
}

/* ODrives - ns=1;s=odrives */

static UA_StatusCode function_nodeset_37_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ODrives");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "odrives"),
UA_NODEID_NUMERIC(ns[0], 85LU),
UA_NODEID_NUMERIC(ns[0], 35LU),
UA_QUALIFIEDNAME(ns[1], "ODrives"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_37_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives")
);
}

/* ODrive - ns=1;i=2001 */

static UA_StatusCode function_nodeset_38_begin(UA_Server *server, UA_UInt16* ns) {
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

static UA_StatusCode function_nodeset_38_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2001LU)
);
}

/* rearright - ns=1;s=odrives.rearright */

static UA_StatusCode function_nodeset_39_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "rearright");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "ODrive");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "odrives.rearright"),
UA_NODEID_STRING(ns[1], "odrives"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "rearright"),
UA_NODEID_NUMERIC(ns[1], 2001LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_39_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearright")
);
}

/* VbusVoltage - ns=1;s=odrives.rearright.vbusvoltage */

static UA_StatusCode function_nodeset_40_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearright.vbusvoltage"),
UA_NODEID_STRING(ns[1], "odrives.rearright"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "VbusVoltage"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_40_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearright.vbusvoltage")
);
}

/* SensorlessEstimates - ns=1;s=odrives.rearright.sensorlessestimates */

static UA_StatusCode function_nodeset_41_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "SensorlessEstimates");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "odrives.rearright.sensorlessestimates"),
UA_NODEID_STRING(ns[1], "odrives.rearright"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Sensorless"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_41_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearright.sensorlessestimates")
);
}

/* Velocity - ns=1;s=odrives.rearright.sensorlessestimates.velocity */

static UA_StatusCode function_nodeset_42_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearright.sensorlessestimates.velocity"),
UA_NODEID_STRING(ns[1], "odrives.rearright.sensorlessestimates"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Velocity"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_42_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearright.sensorlessestimates.velocity")
);
}

/* Position - ns=1;s=odrives.rearright.sensorlessestimates.position */

static UA_StatusCode function_nodeset_43_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearright.sensorlessestimates.position"),
UA_NODEID_STRING(ns[1], "odrives.rearright.sensorlessestimates"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Position"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_43_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearright.sensorlessestimates.position")
);
}

/* IQ - ns=1;s=odrives.rearright.iq */

static UA_StatusCode function_nodeset_44_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "IQ");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "odrives.rearright.iq"),
UA_NODEID_STRING(ns[1], "odrives.rearright"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "IQ"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_44_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearright.iq")
);
}

/* Setpoint - ns=1;s=odrives.rearright.iq.setpoint */

static UA_StatusCode function_nodeset_45_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearright.iq.setpoint"),
UA_NODEID_STRING(ns[1], "odrives.rearright.iq"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Setpoint"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_45_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearright.iq.setpoint")
);
}

/* Measured - ns=1;s=odrives.rearright.iq.measured */

static UA_StatusCode function_nodeset_46_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearright.iq.measured"),
UA_NODEID_STRING(ns[1], "odrives.rearright.iq"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Measured"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_46_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearright.iq.measured")
);
}

/* Error - ns=1;s=odrives.rearright.error */

static UA_StatusCode function_nodeset_47_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Error");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "odrives.rearright.error"),
UA_NODEID_STRING(ns[1], "odrives.rearright"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Error"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_47_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearright.error")
);
}

/* Sensorless - ns=1;s=odrives.rearright.error.sensorless */

static UA_StatusCode function_nodeset_48_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearright.error.sensorless"),
UA_NODEID_STRING(ns[1], "odrives.rearright.error"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Sensorless"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_48_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearright.error.sensorless")
);
}

/* Motor - ns=1;s=odrives.rearright.error.motor */

static UA_StatusCode function_nodeset_49_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearright.error.motor"),
UA_NODEID_STRING(ns[1], "odrives.rearright.error"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Motor"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_49_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearright.error.motor")
);
}

/* Encoder - ns=1;s=odrives.rearright.error.encoder */

static UA_StatusCode function_nodeset_50_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearright.error.encoder"),
UA_NODEID_STRING(ns[1], "odrives.rearright.error"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Encoder"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_50_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearright.error.encoder")
);
}

/* Controller - ns=1;s=odrives.rearright.error.controller */

static UA_StatusCode function_nodeset_51_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearright.error.controller"),
UA_NODEID_STRING(ns[1], "odrives.rearright.error"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Controller"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_51_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearright.error.controller")
);
}

/* Board - ns=1;s=odrives.rearright.error.board */

static UA_StatusCode function_nodeset_52_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearright.error.board"),
UA_NODEID_STRING(ns[1], "odrives.rearright.error"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Board"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_52_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearright.error.board")
);
}

/* Axis - ns=1;s=odrives.rearright.error.axis */

static UA_StatusCode function_nodeset_53_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearright.error.axis"),
UA_NODEID_STRING(ns[1], "odrives.rearright.error"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Axis"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_53_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearright.error.axis")
);
}

/* EncoderEstimates - ns=1;s=odrives.rearright.encoderestimates */

static UA_StatusCode function_nodeset_54_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "EncoderEstimates");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "odrives.rearright.encoderestimates"),
UA_NODEID_STRING(ns[1], "odrives.rearright"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "EncoderEstimates"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_54_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearright.encoderestimates")
);
}

/* Velocity - ns=1;s=odrives.rearright.encoderestimates.velocity */

static UA_StatusCode function_nodeset_55_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearright.encoderestimates.velocity"),
UA_NODEID_STRING(ns[1], "odrives.rearright.encoderestimates"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Velocity"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_55_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearright.encoderestimates.velocity")
);
}

/* Position - ns=1;s=odrives.rearright.encoderestimates.position */

static UA_StatusCode function_nodeset_56_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearright.encoderestimates.position"),
UA_NODEID_STRING(ns[1], "odrives.rearright.encoderestimates"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Position"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_56_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearright.encoderestimates.position")
);
}

/* EncoderCounts - ns=1;s=odrives.rearright.encodercounts */

static UA_StatusCode function_nodeset_57_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "EncoderCounts");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "odrives.rearright.encodercounts"),
UA_NODEID_STRING(ns[1], "odrives.rearright"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "EncoderCounts"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_57_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearright.encodercounts")
);
}

/* Shadow - ns=1;s=odrives.rearright.encodercounts.shadow */

static UA_StatusCode function_nodeset_58_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearright.encodercounts.shadow"),
UA_NODEID_STRING(ns[1], "odrives.rearright.encodercounts"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Shadow"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_58_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearright.encodercounts.shadow")
);
}

/* CPR - ns=1;s=odrives.rearright.encodercounts.cpr */

static UA_StatusCode function_nodeset_59_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearright.encodercounts.cpr"),
UA_NODEID_STRING(ns[1], "odrives.rearright.encodercounts"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "CPR"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_59_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearright.encodercounts.cpr")
);
}

/* ControllerStatus - ns=1;s=odrives.rearright.controllerstatus */

static UA_StatusCode function_nodeset_60_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearright.controllerstatus"),
UA_NODEID_STRING(ns[1], "odrives.rearright"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "ControllerStatus"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_60_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearright.controllerstatus")
);
}

/* AxisState - ns=1;s=odrives.rearright.axisstate */

static UA_StatusCode function_nodeset_61_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearright.axisstate"),
UA_NODEID_STRING(ns[1], "odrives.rearright"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "AxisState"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_61_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearright.axisstate")
);
}

/* rearleft - ns=1;s=odrives.rearleft */

static UA_StatusCode function_nodeset_62_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "rearleft");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "ODrive");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "odrives.rearleft"),
UA_NODEID_STRING(ns[1], "odrives"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "rearleft"),
UA_NODEID_NUMERIC(ns[1], 2001LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_62_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearleft")
);
}

/* VbusVoltage - ns=1;s=odrives.rearleft.vbusvoltage */

static UA_StatusCode function_nodeset_63_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearleft.vbusvoltage"),
UA_NODEID_STRING(ns[1], "odrives.rearleft"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "VbusVoltage"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_63_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearleft.vbusvoltage")
);
}

/* SensorlessEstimates - ns=1;s=odrives.rearleft.sensorlessestimates */

static UA_StatusCode function_nodeset_64_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "SensorlessEstimates");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "odrives.rearleft.sensorlessestimates"),
UA_NODEID_STRING(ns[1], "odrives.rearleft"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Sensorless"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_64_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearleft.sensorlessestimates")
);
}

/* Velocity - ns=1;s=odrives.rearleft.sensorlessestimates.velocity */

static UA_StatusCode function_nodeset_65_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearleft.sensorlessestimates.velocity"),
UA_NODEID_STRING(ns[1], "odrives.rearleft.sensorlessestimates"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Velocity"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_65_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearleft.sensorlessestimates.velocity")
);
}

/* Position - ns=1;s=odrives.rearleft.sensorlessestimates.position */

static UA_StatusCode function_nodeset_66_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearleft.sensorlessestimates.position"),
UA_NODEID_STRING(ns[1], "odrives.rearleft.sensorlessestimates"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Position"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_66_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearleft.sensorlessestimates.position")
);
}

/* IQ - ns=1;s=odrives.rearleft.iq */

static UA_StatusCode function_nodeset_67_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "IQ");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "odrives.rearleft.iq"),
UA_NODEID_STRING(ns[1], "odrives.rearleft"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "IQ"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_67_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearleft.iq")
);
}

/* Setpoint - ns=1;s=odrives.rearleft.iq.setpoint */

static UA_StatusCode function_nodeset_68_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearleft.iq.setpoint"),
UA_NODEID_STRING(ns[1], "odrives.rearleft.iq"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Setpoint"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_68_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearleft.iq.setpoint")
);
}

/* Measured - ns=1;s=odrives.rearleft.iq.measured */

static UA_StatusCode function_nodeset_69_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearleft.iq.measured"),
UA_NODEID_STRING(ns[1], "odrives.rearleft.iq"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Measured"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_69_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearleft.iq.measured")
);
}

/* Error - ns=1;s=odrives.rearleft.error */

static UA_StatusCode function_nodeset_70_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Error");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "odrives.rearleft.error"),
UA_NODEID_STRING(ns[1], "odrives.rearleft"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Error"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_70_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearleft.error")
);
}

/* Sensorless - ns=1;s=odrives.rearleft.error.sensorless */

static UA_StatusCode function_nodeset_71_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearleft.error.sensorless"),
UA_NODEID_STRING(ns[1], "odrives.rearleft.error"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Sensorless"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_71_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearleft.error.sensorless")
);
}

/* Motor - ns=1;s=odrives.rearleft.error.motor */

static UA_StatusCode function_nodeset_72_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearleft.error.motor"),
UA_NODEID_STRING(ns[1], "odrives.rearleft.error"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Motor"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_72_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearleft.error.motor")
);
}

/* Encoder - ns=1;s=odrives.rearleft.error.encoder */

static UA_StatusCode function_nodeset_73_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Encoder");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Encoder");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "odrives.rearleft.error.encoder"),
UA_NODEID_STRING(ns[1], "odrives.rearleft.error"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Encoder"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_73_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearleft.error.encoder")
);
}

/* Controller - ns=1;s=odrives.rearleft.error.controller */

static UA_StatusCode function_nodeset_74_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearleft.error.controller"),
UA_NODEID_STRING(ns[1], "odrives.rearleft.error"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Controller"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_74_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearleft.error.controller")
);
}

/* Board - ns=1;s=odrives.rearleft.error.board */

static UA_StatusCode function_nodeset_75_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearleft.error.board"),
UA_NODEID_STRING(ns[1], "odrives.rearleft.error"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Board"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_75_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearleft.error.board")
);
}

/* Axis - ns=1;s=odrives.rearleft.error.axis */

static UA_StatusCode function_nodeset_76_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearleft.error.axis"),
UA_NODEID_STRING(ns[1], "odrives.rearleft.error"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Axis"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_76_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearleft.error.axis")
);
}

/* EncoderEstimates - ns=1;s=odrives.rearleft.encoderestimates */

static UA_StatusCode function_nodeset_77_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "EncoderEstimates");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "odrives.rearleft.encoderestimates"),
UA_NODEID_STRING(ns[1], "odrives.rearleft"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "EncoderEstimates"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_77_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearleft.encoderestimates")
);
}

/* Velocity - ns=1;s=odrives.rearleft.encoderestimates.velocity */

static UA_StatusCode function_nodeset_78_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearleft.encoderestimates.velocity"),
UA_NODEID_STRING(ns[1], "odrives.rearleft.encoderestimates"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Velocity"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_78_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearleft.encoderestimates.velocity")
);
}

/* Position - ns=1;s=odrives.rearleft.encoderestimates.position */

static UA_StatusCode function_nodeset_79_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearleft.encoderestimates.position"),
UA_NODEID_STRING(ns[1], "odrives.rearleft.encoderestimates"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Position"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_79_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearleft.encoderestimates.position")
);
}

/* EncoderCounts - ns=1;s=odrives.rearleft.encodercounts */

static UA_StatusCode function_nodeset_80_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "EncoderCounts");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "odrives.rearleft.encodercounts"),
UA_NODEID_STRING(ns[1], "odrives.rearleft"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "EncoderCounts"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_80_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearleft.encodercounts")
);
}

/* Shadow - ns=1;s=odrives.rearleft.encodercounts.shadow */

static UA_StatusCode function_nodeset_81_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearleft.encodercounts.shadow"),
UA_NODEID_STRING(ns[1], "odrives.rearleft.encodercounts"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Shadow"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_81_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearleft.encodercounts.shadow")
);
}

/* CPR - ns=1;s=odrives.rearleft.encodercounts.cpr */

static UA_StatusCode function_nodeset_82_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearleft.encodercounts.cpr"),
UA_NODEID_STRING(ns[1], "odrives.rearleft.encodercounts"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "CPR"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_82_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearleft.encodercounts.cpr")
);
}

/* ControllerStatus - ns=1;s=odrives.rearleft.controllerstatus */

static UA_StatusCode function_nodeset_83_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearleft.controllerstatus"),
UA_NODEID_STRING(ns[1], "odrives.rearleft"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "ControllerStatus"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_83_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearleft.controllerstatus")
);
}

/* AxisState - ns=1;s=odrives.rearleft.axisstate */

static UA_StatusCode function_nodeset_84_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.rearleft.axisstate"),
UA_NODEID_STRING(ns[1], "odrives.rearleft"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "AxisState"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_84_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.rearleft.axisstate")
);
}

/* FrontRight - ns=1;s=odrives.frontright */

static UA_StatusCode function_nodeset_85_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "FrontRight");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "ODrive");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "odrives.frontright"),
UA_NODEID_STRING(ns[1], "odrives"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "FrontRight"),
UA_NODEID_NUMERIC(ns[1], 2001LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_85_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontright")
);
}

/* VbusVoltage - ns=1;s=odrives.frontright.vbusvoltage */

static UA_StatusCode function_nodeset_86_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontright.vbusvoltage"),
UA_NODEID_STRING(ns[1], "odrives.frontright"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "VbusVoltage"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_86_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontright.vbusvoltage")
);
}

/* SensorlessEstimates - ns=1;s=odrives.frontright.sensorlessestimates */

static UA_StatusCode function_nodeset_87_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "SensorlessEstimates");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "odrives.frontright.sensorlessestimates"),
UA_NODEID_STRING(ns[1], "odrives.frontright"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Sensorless"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_87_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontright.sensorlessestimates")
);
}

/* Velocity - ns=1;s=odrives.frontright.sensorlessestimates.velocity */

static UA_StatusCode function_nodeset_88_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontright.sensorlessestimates.velocity"),
UA_NODEID_STRING(ns[1], "odrives.frontright.sensorlessestimates"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Velocity"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_88_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontright.sensorlessestimates.velocity")
);
}

/* Position - ns=1;s=odrives.frontright.sensorlessestimates.position */

static UA_StatusCode function_nodeset_89_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontright.sensorlessestimates.position"),
UA_NODEID_STRING(ns[1], "odrives.frontright.sensorlessestimates"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Position"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_89_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontright.sensorlessestimates.position")
);
}

/* IQ - ns=1;s=odrives.frontright.iq */

static UA_StatusCode function_nodeset_90_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "IQ");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "odrives.frontright.iq"),
UA_NODEID_STRING(ns[1], "odrives.frontright"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "IQ"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_90_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontright.iq")
);
}

/* Setpoint - ns=1;s=odrives.frontright.iq.setpoint */

static UA_StatusCode function_nodeset_91_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontright.iq.setpoint"),
UA_NODEID_STRING(ns[1], "odrives.frontright.iq"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Setpoint"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_91_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontright.iq.setpoint")
);
}

/* Measured - ns=1;s=odrives.frontright.iq.measured */

static UA_StatusCode function_nodeset_92_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontright.iq.measured"),
UA_NODEID_STRING(ns[1], "odrives.frontright.iq"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Measured"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_92_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontright.iq.measured")
);
}

/* Error - ns=1;s=odrives.frontright.error */

static UA_StatusCode function_nodeset_93_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Error");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "odrives.frontright.error"),
UA_NODEID_STRING(ns[1], "odrives.frontright"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Error"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_93_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontright.error")
);
}

/* Sensorless - ns=1;s=odrives.frontright.error.sensorless */

static UA_StatusCode function_nodeset_94_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontright.error.sensorless"),
UA_NODEID_STRING(ns[1], "odrives.frontright.error"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Sensorless"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_94_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontright.error.sensorless")
);
}

/* Motor - ns=1;s=odrives.frontright.error.motor */

static UA_StatusCode function_nodeset_95_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontright.error.motor"),
UA_NODEID_STRING(ns[1], "odrives.frontright.error"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Motor"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_95_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontright.error.motor")
);
}

/* Encoder - ns=1;s=odrives.frontright.error.encoder */

static UA_StatusCode function_nodeset_96_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Encoder");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Encoder");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "odrives.frontright.error.encoder"),
UA_NODEID_STRING(ns[1], "odrives.frontright.error"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Encoder"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_96_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontright.error.encoder")
);
}

/* Controller - ns=1;s=odrives.frontright.error.controller */

static UA_StatusCode function_nodeset_97_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontright.error.controller"),
UA_NODEID_STRING(ns[1], "odrives.frontright.error"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Controller"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_97_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontright.error.controller")
);
}

/* Board - ns=1;s=odrives.frontright.error.board */

static UA_StatusCode function_nodeset_98_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontright.error.board"),
UA_NODEID_STRING(ns[1], "odrives.frontright.error"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Board"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_98_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontright.error.board")
);
}

/* Axis - ns=1;s=odrives.frontright.error.axis */

static UA_StatusCode function_nodeset_99_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontright.error.axis"),
UA_NODEID_STRING(ns[1], "odrives.frontright.error"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Axis"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_99_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontright.error.axis")
);
}

/* EncoderEstimates - ns=1;s=odrives.frontright.encoderestimates */

static UA_StatusCode function_nodeset_100_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "EncoderEstimates");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "odrives.frontright.encoderestimates"),
UA_NODEID_STRING(ns[1], "odrives.frontright"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "EncoderEstimates"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_100_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontright.encoderestimates")
);
}

/* Velocity - ns=1;s=odrives.frontright.encoderestimates.velocity */

static UA_StatusCode function_nodeset_101_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontright.encoderestimates.velocity"),
UA_NODEID_STRING(ns[1], "odrives.frontright.encoderestimates"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Velocity"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_101_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontright.encoderestimates.velocity")
);
}

/* Position - ns=1;s=odrives.frontright.encoderestimates.position */

static UA_StatusCode function_nodeset_102_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontright.encoderestimates.position"),
UA_NODEID_STRING(ns[1], "odrives.frontright.encoderestimates"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Position"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_102_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontright.encoderestimates.position")
);
}

/* EncoderCounts - ns=1;s=odrives.frontright.encodercounts */

static UA_StatusCode function_nodeset_103_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "EncoderCounts");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "odrives.frontright.encodercounts"),
UA_NODEID_STRING(ns[1], "odrives.frontright"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "EncoderCounts"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_103_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontright.encodercounts")
);
}

/* Shadow - ns=1;s=odrives.frontright.encodercounts.shadow */

static UA_StatusCode function_nodeset_104_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontright.encodercounts.shadow"),
UA_NODEID_STRING(ns[1], "odrives.frontright.encodercounts"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Shadow"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_104_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontright.encodercounts.shadow")
);
}

/* CPR - ns=1;s=odrives.frontright.encodercounts.cpr */

static UA_StatusCode function_nodeset_105_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontright.encodercounts.cpr"),
UA_NODEID_STRING(ns[1], "odrives.frontright.encodercounts"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "CPR"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_105_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontright.encodercounts.cpr")
);
}

/* ControllerStatus - ns=1;s=odrives.frontright.controllerstatus */

static UA_StatusCode function_nodeset_106_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontright.controllerstatus"),
UA_NODEID_STRING(ns[1], "odrives.frontright"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "ControllerStatus"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_106_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontright.controllerstatus")
);
}

/* AxisState - ns=1;s=odrives.frontright.axisstate */

static UA_StatusCode function_nodeset_107_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontright.axisstate"),
UA_NODEID_STRING(ns[1], "odrives.frontright"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "AxisState"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_107_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontright.axisstate")
);
}

/* frontleft - ns=1;s=odrives.frontleft */

static UA_StatusCode function_nodeset_108_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "frontleft");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "ODrive");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "odrives.frontleft"),
UA_NODEID_STRING(ns[1], "odrives"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "frontleft"),
UA_NODEID_NUMERIC(ns[1], 2001LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_108_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontleft")
);
}

/* VbusVoltage - ns=1;s=odrives.frontleft.vbusvoltage */

static UA_StatusCode function_nodeset_109_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontleft.vbusvoltage"),
UA_NODEID_STRING(ns[1], "odrives.frontleft"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "VbusVoltage"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_109_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontleft.vbusvoltage")
);
}

/* SensorlessEstimates - ns=1;s=odrives.frontleft.sensorlessestimates */

static UA_StatusCode function_nodeset_110_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "SensorlessEstimates");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "odrives.frontleft.sensorlessestimates"),
UA_NODEID_STRING(ns[1], "odrives.frontleft"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Sensorless"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_110_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontleft.sensorlessestimates")
);
}

/* Velocity - ns=1;s=odrives.frontleft.sensorlessestimates.velocity */

static UA_StatusCode function_nodeset_111_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontleft.sensorlessestimates.velocity"),
UA_NODEID_STRING(ns[1], "odrives.frontleft.sensorlessestimates"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Velocity"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_111_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontleft.sensorlessestimates.velocity")
);
}

/* Position - ns=1;s=odrives.frontleft.sensorlessestimates.position */

static UA_StatusCode function_nodeset_112_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontleft.sensorlessestimates.position"),
UA_NODEID_STRING(ns[1], "odrives.frontleft.sensorlessestimates"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Position"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_112_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontleft.sensorlessestimates.position")
);
}

/* IQ - ns=1;s=odrives.frontleft.iq */

static UA_StatusCode function_nodeset_113_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "IQ");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "odrives.frontleft.iq"),
UA_NODEID_STRING(ns[1], "odrives.frontleft"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "IQ"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_113_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontleft.iq")
);
}

/* Setpoint - ns=1;s=odrives.frontleft.iq.setpoint */

static UA_StatusCode function_nodeset_114_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontleft.iq.setpoint"),
UA_NODEID_STRING(ns[1], "odrives.frontleft.iq"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Setpoint"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_114_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontleft.iq.setpoint")
);
}

/* Measured - ns=1;s=odrives.frontleft.iq.measured */

static UA_StatusCode function_nodeset_115_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontleft.iq.measured"),
UA_NODEID_STRING(ns[1], "odrives.frontleft.iq"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Measured"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_115_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontleft.iq.measured")
);
}

/* Error - ns=1;s=odrives.frontleft.error */

static UA_StatusCode function_nodeset_116_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Error");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "odrives.frontleft.error"),
UA_NODEID_STRING(ns[1], "odrives.frontleft"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Error"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_116_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontleft.error")
);
}

/* Sensorless - ns=1;s=odrives.frontleft.error.sensorless */

static UA_StatusCode function_nodeset_117_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontleft.error.sensorless"),
UA_NODEID_STRING(ns[1], "odrives.frontleft.error"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Sensorless"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_117_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontleft.error.sensorless")
);
}

/* Motor - ns=1;s=odrives.frontleft.error.motor */

static UA_StatusCode function_nodeset_118_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontleft.error.motor"),
UA_NODEID_STRING(ns[1], "odrives.frontleft.error"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Motor"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_118_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontleft.error.motor")
);
}

/* Encoder - ns=1;s=odrives.frontleft.error.encoder */

static UA_StatusCode function_nodeset_119_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7LU);
attr.displayName = UA_LOCALIZEDTEXT("", "Encoder");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Encoder");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_STRING(ns[1], "odrives.frontleft.error.encoder"),
UA_NODEID_STRING(ns[1], "odrives.frontleft.error"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Encoder"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_119_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontleft.error.encoder")
);
}

/* Controller - ns=1;s=odrives.frontleft.error.controller */

static UA_StatusCode function_nodeset_120_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontleft.error.controller"),
UA_NODEID_STRING(ns[1], "odrives.frontleft.error"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Controller"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_120_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontleft.error.controller")
);
}

/* Board - ns=1;s=odrives.frontleft.error.board */

static UA_StatusCode function_nodeset_121_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontleft.error.board"),
UA_NODEID_STRING(ns[1], "odrives.frontleft.error"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Board"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_121_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontleft.error.board")
);
}

/* Axis - ns=1;s=odrives.frontleft.error.axis */

static UA_StatusCode function_nodeset_122_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontleft.error.axis"),
UA_NODEID_STRING(ns[1], "odrives.frontleft.error"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Axis"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_122_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontleft.error.axis")
);
}

/* EncoderEstimates - ns=1;s=odrives.frontleft.encoderestimates */

static UA_StatusCode function_nodeset_123_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "EncoderEstimates");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "odrives.frontleft.encoderestimates"),
UA_NODEID_STRING(ns[1], "odrives.frontleft"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "EncoderEstimates"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_123_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontleft.encoderestimates")
);
}

/* Velocity - ns=1;s=odrives.frontleft.encoderestimates.velocity */

static UA_StatusCode function_nodeset_124_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontleft.encoderestimates.velocity"),
UA_NODEID_STRING(ns[1], "odrives.frontleft.encoderestimates"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Velocity"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_124_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontleft.encoderestimates.velocity")
);
}

/* Position - ns=1;s=odrives.frontleft.encoderestimates.position */

static UA_StatusCode function_nodeset_125_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontleft.encoderestimates.position"),
UA_NODEID_STRING(ns[1], "odrives.frontleft.encoderestimates"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Position"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_125_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontleft.encoderestimates.position")
);
}

/* EncoderCounts - ns=1;s=odrives.frontleft.encodercounts */

static UA_StatusCode function_nodeset_126_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "EncoderCounts");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_STRING(ns[1], "odrives.frontleft.encodercounts"),
UA_NODEID_STRING(ns[1], "odrives.frontleft"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "EncoderCounts"),
UA_NODEID_NUMERIC(ns[0], 58LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_126_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontleft.encodercounts")
);
}

/* Shadow - ns=1;s=odrives.frontleft.encodercounts.shadow */

static UA_StatusCode function_nodeset_127_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontleft.encodercounts.shadow"),
UA_NODEID_STRING(ns[1], "odrives.frontleft.encodercounts"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Shadow"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_127_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontleft.encodercounts.shadow")
);
}

/* CPR - ns=1;s=odrives.frontleft.encodercounts.cpr */

static UA_StatusCode function_nodeset_128_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontleft.encodercounts.cpr"),
UA_NODEID_STRING(ns[1], "odrives.frontleft.encodercounts"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "CPR"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_128_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontleft.encodercounts.cpr")
);
}

/* ControllerStatus - ns=1;s=odrives.frontleft.controllerstatus */

static UA_StatusCode function_nodeset_129_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontleft.controllerstatus"),
UA_NODEID_STRING(ns[1], "odrives.frontleft"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "ControllerStatus"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_129_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontleft.controllerstatus")
);
}

/* AxisState - ns=1;s=odrives.frontleft.axisstate */

static UA_StatusCode function_nodeset_130_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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
UA_NODEID_STRING(ns[1], "odrives.frontleft.axisstate"),
UA_NODEID_STRING(ns[1], "odrives.frontleft"),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "AxisState"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
if (retVal != UA_STATUSCODE_GOOD) return retVal;
return retVal;
}

static UA_StatusCode function_nodeset_130_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_STRING(ns[1], "odrives.frontleft.axisstate")
);
}

/* VbusVoltage - ns=1;i=2023 */

static UA_StatusCode function_nodeset_131_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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

static UA_StatusCode function_nodeset_131_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2023LU)
);
}

/* SensorlessEstimates - ns=1;i=2020 */

static UA_StatusCode function_nodeset_132_begin(UA_Server *server, UA_UInt16* ns) {
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

static UA_StatusCode function_nodeset_132_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2020LU)
);
}

/* Velocity - ns=1;i=2022 */

static UA_StatusCode function_nodeset_133_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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

static UA_StatusCode function_nodeset_133_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2022LU)
);
}

/* Position - ns=1;i=2021 */

static UA_StatusCode function_nodeset_134_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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

static UA_StatusCode function_nodeset_134_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2021LU)
);
}

/* IQ - ns=1;i=2017 */

static UA_StatusCode function_nodeset_135_begin(UA_Server *server, UA_UInt16* ns) {
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

static UA_StatusCode function_nodeset_135_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2017LU)
);
}

/* Setpoint - ns=1;i=2019 */

static UA_StatusCode function_nodeset_136_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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

static UA_StatusCode function_nodeset_136_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2019LU)
);
}

/* Measured - ns=1;i=2018 */

static UA_StatusCode function_nodeset_137_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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

static UA_StatusCode function_nodeset_137_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2018LU)
);
}

/* Error - ns=1;i=2010 */

static UA_StatusCode function_nodeset_138_begin(UA_Server *server, UA_UInt16* ns) {
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

static UA_StatusCode function_nodeset_138_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2010LU)
);
}

/* Sensorless - ns=1;i=2016 */

static UA_StatusCode function_nodeset_139_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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

static UA_StatusCode function_nodeset_139_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2016LU)
);
}

/* Motor - ns=1;i=2015 */

static UA_StatusCode function_nodeset_140_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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

static UA_StatusCode function_nodeset_140_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2015LU)
);
}

/* Encoder - ns=1;i=2014 */

static UA_StatusCode function_nodeset_141_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -2;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7LU);
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

static UA_StatusCode function_nodeset_141_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2014LU)
);
}

/* Controller - ns=1;i=2013 */

static UA_StatusCode function_nodeset_142_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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

static UA_StatusCode function_nodeset_142_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2013LU)
);
}

/* Board - ns=1;i=2012 */

static UA_StatusCode function_nodeset_143_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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

static UA_StatusCode function_nodeset_143_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2012LU)
);
}

/* Axis - ns=1;i=2011 */

static UA_StatusCode function_nodeset_144_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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

static UA_StatusCode function_nodeset_144_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2011LU)
);
}

/* EncoderEstimates - ns=1;i=2007 */

static UA_StatusCode function_nodeset_145_begin(UA_Server *server, UA_UInt16* ns) {
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

static UA_StatusCode function_nodeset_145_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2007LU)
);
}

/* Velocity - ns=1;i=2009 */

static UA_StatusCode function_nodeset_146_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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

static UA_StatusCode function_nodeset_146_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2009LU)
);
}

/* Position - ns=1;i=2008 */

static UA_StatusCode function_nodeset_147_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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

static UA_StatusCode function_nodeset_147_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2008LU)
);
}

/* EncoderCounts - ns=1;i=2004 */

static UA_StatusCode function_nodeset_148_begin(UA_Server *server, UA_UInt16* ns) {
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

static UA_StatusCode function_nodeset_148_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2004LU)
);
}

/* Shadow - ns=1;i=2006 */

static UA_StatusCode function_nodeset_149_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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

static UA_StatusCode function_nodeset_149_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2006LU)
);
}

/* CPR - ns=1;i=2005 */

static UA_StatusCode function_nodeset_150_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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

static UA_StatusCode function_nodeset_150_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2005LU)
);
}

/* ControllerStatus - ns=1;i=2003 */

static UA_StatusCode function_nodeset_151_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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

static UA_StatusCode function_nodeset_151_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2003LU)
);
}

/* AxisState - ns=1;i=2002 */

static UA_StatusCode function_nodeset_152_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.historizing = true;
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

static UA_StatusCode function_nodeset_152_finish(UA_Server *server, UA_UInt16* ns) {
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
if((retVal = function_nodeset_148_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_149_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_150_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_151_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_152_begin(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_152_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_151_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_150_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_149_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
if((retVal = function_nodeset_148_finish(server, ns)) != UA_STATUSCODE_GOOD) return retVal;
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
