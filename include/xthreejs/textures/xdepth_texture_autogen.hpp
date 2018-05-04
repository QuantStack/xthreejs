#ifndef XTHREE_DEPTH_TEXTURE_HPP
#define XTHREE_DEPTH_TEXTURE_HPP

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
    // depth_texture declaration
    //

    template<class D>
    class xdepth_texture : public xtexture<D>
    {
    public:

        using base_type = xtexture<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(int, derived_type, width, 0);
        XPROPERTY(int, derived_type, height, 0);
        XPROPERTY(std::string, derived_type, format, "DepthFormat", xenums::DepthFormats);
        XPROPERTY(std::string, derived_type, type, "UnsignedShortType", xenums::DataTypes);
        XPROPERTY(std::string, derived_type, minFilter, "NearestFilter", xenums::Filters);
        XPROPERTY(std::string, derived_type, magFilter, "NearestFilter", xenums::Filters);
        XPROPERTY(bool, derived_type, flipY, false);
        XPROPERTY(bool, derived_type, generateMipmaps, false);


    protected:

        xdepth_texture();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using depth_texture = xw::xmaterialize<xdepth_texture>;

    using depth_texture_generator = xw::xgenerator<xdepth_texture>;

    //
    // depth_texture implementation
    //


    template <class D>
    inline void xdepth_texture<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(width, state, buffers);
        xw::set_patch_from_property(height, state, buffers);
        xw::set_patch_from_property(format, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
        xw::set_patch_from_property(minFilter, state, buffers);
        xw::set_patch_from_property(magFilter, state, buffers);
        xw::set_patch_from_property(flipY, state, buffers);
        xw::set_patch_from_property(generateMipmaps, state, buffers);
    }

    template <class D>
    inline void xdepth_texture<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(width, patch, buffers);
        xw::set_property_from_patch(height, patch, buffers);
        xw::set_property_from_patch(format, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
        xw::set_property_from_patch(minFilter, patch, buffers);
        xw::set_property_from_patch(magFilter, patch, buffers);
        xw::set_property_from_patch(flipY, patch, buffers);
        xw::set_property_from_patch(generateMipmaps, patch, buffers);
    }

    template <class D>
    inline xdepth_texture<D>::xdepth_texture()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xdepth_texture<D>::set_defaults()
    {
        this->_model_name() = "DepthTextureModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xdepth_texture>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xdepth_texture>>;
    extern template class xw::xgenerator<xthree::xdepth_texture>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xdepth_texture>>;
#endif

#endif