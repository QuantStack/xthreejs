#include "xthreejs/objects/xclone_array_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xclone_array>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xclone_array>;
    template xw::xmaterialize<xthree::xclone_array>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xclone_array>>;
    template class xw::xgenerator<xthree::xclone_array>;
    template xw::xgenerator<xthree::xclone_array>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xclone_array>>;
#endif
