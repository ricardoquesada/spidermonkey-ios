/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 * vim: set ts=4 sw=4 et tw=99:
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef jsion_codegen_x64_h__
#define jsion_codegen_x64_h__

#include "ion/x64/Assembler-x64.h"
#include "ion/shared/CodeGenerator-x86-shared.h"

namespace js {
namespace ion {

class CodeGeneratorX64 : public CodeGeneratorX86Shared
{
    CodeGeneratorX64 *thisFromCtor() {
        return this;
    }

  protected:
    ValueOperand ToValue(LInstruction *ins, size_t pos);
    ValueOperand ToOutValue(LInstruction *ins);


    void loadUnboxedValue(Operand source, MIRType type, const LDefinition *dest);
    void storeUnboxedValue(const LAllocation *value, MIRType valueType,
                           Operand dest, MIRType slotType);

    void storeElementTyped(const LAllocation *value, MIRType valueType, MIRType elementType,
                           const Register &elements, const LAllocation *index);

  public:
    CodeGeneratorX64(MIRGenerator *gen, LIRGraph &graph);

  public:
    bool visitValue(LValue *value);
    bool visitOsrValue(LOsrValue *value);
    bool visitBox(LBox *box);
    bool visitUnbox(LUnbox *unbox);
    bool visitDouble(LDouble *ins);
    bool visitLoadSlotV(LLoadSlotV *ins);
    bool visitLoadSlotT(LLoadSlotT *load);
    bool visitStoreSlotT(LStoreSlotT *store);
    bool visitLoadElementT(LLoadElementT *load);
    bool visitImplicitThis(LImplicitThis *lir);
    bool visitRecompileCheck(LRecompileCheck *lir);
    bool visitInterruptCheck(LInterruptCheck *lir);
    bool visitCompareB(LCompareB *lir);
    bool visitCompareBAndBranch(LCompareBAndBranch *lir);
};

typedef CodeGeneratorX64 CodeGeneratorSpecific;

} // namespace ion
} // namespace js

#endif // jsion_codegen_x64_h__

