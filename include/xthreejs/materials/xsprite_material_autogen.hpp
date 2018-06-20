#ifndef XTHREE_SPRITE_MATERIAL_HPP
#define XTHREE_SPRITE_MATERIAL_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xmaterial.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // sprite_material declaration
    //

    template<class D>
    class xsprite_material : public xmaterial<D>
    {
    public:

        using base_type = xmaterial<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xw::html_color, derived_type, color, "#ffffff");
        XPROPERTY(bool, derived_type, fog, false);
        XPROPERTY(bool, derived_type, lights, false);
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, map);
        XPROPERTY(double, derived_type, rotation, 0);
        XPROPERTY(std::string, derived_type, type, "SpriteMaterial");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xsprite_material();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using sprite_material = xw::xmaterialize<xsprite_material>;

    using sprite_material_generator = xw::xgenerator<xsprite_material>;

    //
    // sprite_material implementation
    //


    template <class D>
    inline void xsprite_material<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(color, state, buffers);
        xw::set_patch_from_property(fog, state, buffers);
        xw::set_patch_from_property(lights, state, buffers);
        xw::set_patch_from_property(map, state, buffers);
        xw::set_patch_from_property(rotation, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xsprite_material<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(color, patch, buffers);
        xw::set_property_from_patch(fog, patch, buffers);
        xw::set_property_from_patch(lights, patch, buffers);
        xw::set_property_from_patch(map, patch, buffers);
        xw::set_property_from_patch(rotation, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xsprite_material<D>::xsprite_material()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xsprite_material<D>::set_defaults()
    {
        this->_model_name() = "SpriteMaterialModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xsprite_material>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xsprite_material>;
        extern template xw::xmaterialize<xthree::xsprite_material>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xsprite_material>>;
        extern template class xw::xgenerator<xthree::xsprite_material>;
        extern template xw::xgenerator<xthree::xsprite_material>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xsprite_material>>;
    #endif
#endif

#endif