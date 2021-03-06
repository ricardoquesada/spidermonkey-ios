# -*- Mode: makefile -*-
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ..
topsrcdir	= ..
srcdir		= ../jsapi-tests
VPATH		= ../jsapi-tests

include $(DEPTH)/config/autoconf.mk

PROGRAM         = jsapi-tests$(BIN_SUFFIX)

CPPSRCS = \
  tests.cpp \
  selfTest.cpp \
  testAddPropertyPropcache.cpp \
  testArrayBuffer.cpp \
  testArgumentsObject.cpp \
  testBindCallable.cpp \
  testBug604087.cpp \
  testCallNonGenericMethodOnProxy.cpp \
  testChromeBuffer.cpp \
  testClassGetter.cpp \
  testCloneScript.cpp \
  testConservativeGC.cpp \
  testContexts.cpp \
  testCustomIterator.cpp \
  testDebugger.cpp \
  testDeepFreeze.cpp \
  testDefineGetterSetterNonEnumerable.cpp \
  testDefineProperty.cpp \
  testExtendedEq.cpp \
  testExternalStrings.cpp \
  testFuncCallback.cpp \
  testFunctionProperties.cpp \
  testGCOutOfMemory.cpp \
  testOOM.cpp \
  testGetPropertyDefault.cpp \
  testHashTable.cpp \
  testIndexToString.cpp \
  testIntString.cpp \
  testIntTypesABI.cpp \
  testIntern.cpp \
  testLookup.cpp \
  testLooselyEqual.cpp \
  testNewObject.cpp \
  testOps.cpp \
  testOriginPrincipals.cpp \
  testParseJSON.cpp \
  testPropCache.cpp \
  testRegExp.cpp \
  testResolveRecursion.cpp \
  testSameValue.cpp \
  testScriptInfo.cpp \
  testScriptObject.cpp \
  testSetProperty.cpp \
  testStringBuffer.cpp \
  testTrap.cpp \
  testTypedArrays.cpp \
  testVersion.cpp \
  testXDR.cpp \
  testProfileStrings.cpp \
  testJSEvaluateScript.cpp \
  testErrorCopying.cpp \
  $(NULL)

# Disabled: an entirely unrelated test seems to cause this to fail.  Moreover,
# given the test's dependence on interactions between the compiler, the GC, and
# conservative stack scanning, the fix isn't obvious: more investigation
# needed.
#CPPSRCS += \
#  testRegExpInstanceProperties.cpp \
#  $(NULL)

DEFINES         += -DEXPORT_JS_API
# Building against js_static requires that we declare mfbt sybols "exported"
# on its behalf.
DEFINES         += -DIMPL_MFBT

LIBS      = $(DEPTH)/$(LIB_PREFIX)js_static.$(LIB_SUFFIX) $(NSPR_LIBS) $(MOZ_ZLIB_LIBS)

LOCAL_INCLUDES += -I$(topsrcdir) -I..

include $(topsrcdir)/config/rules.mk

check::
	$(wildcard $(RUN_TEST_PROGRAM)) $(DIST)/bin/jsapi-tests$(BIN_SUFFIX)
