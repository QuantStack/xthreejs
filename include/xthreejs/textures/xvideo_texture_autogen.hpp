#ifndef XTHREE_VIDEO_TEXTURE_HPP
#define XTHREE_VIDEO_TEXTURE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // video_texture declaration
    //

    template<class D>
    class xvideo_texture : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xvideo_texture();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using video_texture = xw::xmaterialize<xvideo_texture>;

    using video_texture_generator = xw::xgenerator<xvideo_texture>;

    //
    // video_texture implementation
    //


    template <class D>
    inline void xvideo_texture<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xvideo_texture<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xvideo_texture<D>::xvideo_texture()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xvideo_texture<D>::set_defaults()
    {
        this->_model_name() = "VideoTextureModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xvideo_texture>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xvideo_texture>;
        extern template xw::xmaterialize<xthree::xvideo_texture>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xvideo_texture>>;
        extern template class xw::xgenerator<xthree::xvideo_texture>;
        extern template xw::xgenerator<xthree::xvideo_texture>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xvideo_texture>>;
    #endif
#endif

#endif