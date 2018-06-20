#include "xthreejs/extras/objects/ximmediate_render_object_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::ximmediate_render_object>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::ximmediate_render_object>;
    template xw::xmaterialize<xthree::ximmediate_render_object>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::ximmediate_render_object>>;
    template class xw::xgenerator<xthree::ximmediate_render_object>;
    template xw::xgenerator<xthree::ximmediate_render_object>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::ximmediate_render_object>>;
#endif
