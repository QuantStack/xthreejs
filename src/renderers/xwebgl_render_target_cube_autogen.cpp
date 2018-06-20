#include "xthreejs/renderers/xwebgl_render_target_cube_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xwebgl_render_target_cube>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xwebgl_render_target_cube>;
    template xw::xmaterialize<xthree::xwebgl_render_target_cube>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_render_target_cube>>;
    template class xw::xgenerator<xthree::xwebgl_render_target_cube>;
    template xw::xgenerator<xthree::xwebgl_render_target_cube>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xwebgl_render_target_cube>>;
#endif
