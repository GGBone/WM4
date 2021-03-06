// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4GraphicsPCH.h"
#include "Wm4MaterialTextureEffect.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,MaterialTextureEffect,ShaderEffect);
WM4_IMPLEMENT_STREAM(MaterialTextureEffect);
WM4_IMPLEMENT_DEFAULT_STREAM(MaterialTextureEffect,ShaderEffect);
WM4_IMPLEMENT_DEFAULT_NAME_ID(MaterialTextureEffect,ShaderEffect);

//----------------------------------------------------------------------------
MaterialTextureEffect::MaterialTextureEffect (const std::string& rkBaseName)
    :
    ShaderEffect(1)
{
    m_kVShader[0] = WM4_NEW VertexShader("MaterialTexture");
    m_kPShader[0] = WM4_NEW PixelShader("MaterialTexture");

    m_kPShader[0]->SetTextureQuantity(1);
    m_kPShader[0]->SetImageName(0,rkBaseName);
}
//----------------------------------------------------------------------------
MaterialTextureEffect::MaterialTextureEffect ()
{
}
//----------------------------------------------------------------------------
MaterialTextureEffect::~MaterialTextureEffect ()
{
}
//----------------------------------------------------------------------------
