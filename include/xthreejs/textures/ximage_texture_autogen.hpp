#ifndef XTHREE_IMAGE_TEXTURE_HPP
#define XTHREE_IMAGE_TEXTURE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xtexture_autogen.hpp"

namespace xthree
{
    //
    // image_texture declaration
    //

    template<class D>
    class ximage_texture : public xtexture<D>
    {
    public:

        using base_type = xtexture<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(std::string, derived_type, imageUri, "");


    protected:

        ximage_texture();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using image_texture = xw::xmaterialize<ximage_texture>;

    using image_texture_generator = xw::xgenerator<ximage_texture>;

    //
    // image_texture implementation
    //


    template <class D>
    inline void ximage_texture<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(imageUri, state, buffers);
    }

    template <class D>
    inline void ximage_texture<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(imageUri, patch, buffers);
    }

    template <class D>
    inline ximage_texture<D>::ximage_texture()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void ximage_texture<D>::set_defaults()
    {
        this->_model_name() = "ImageTextureModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::ximage_texture>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::ximage_texture>>;
    extern template class xw::xgenerator<xthree::ximage_texture>;
    extern template class xw::xtransport<xw::xgenerator<xthree::ximage_texture>>;
#endif

#endif